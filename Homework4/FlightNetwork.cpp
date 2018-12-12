/*
 * Title: Hashing and Graphs
 * Author: EFE ACER
 * ID: 21602217
 * Section: 3
 * Assignment: 4
 * Description: This file implements the public and private interfaces of FlightNetwork class
 *              and its helper classes. Well-known graph traversal algorithms such as Bread
 *              First Traversal and Depth First Traversal are mainly used strategies to implement
 *              the public interface of the FlightNetwork class. Formal comments of the functions
 *              can be found in the corresponding header file.
 */

#include "FlightNetwork.h"
#include <iostream> //cout and cin
#include <fstream> //fstream
#include <stddef.h> //NULL

//implementation of FlightNetwork class starts

//constants
const int NUM_AIRPORTS = 3425;
const int NUM_FLIGHTS = 67652;

FlightNetwork::FlightNetwork() {
    numAirports = NUM_AIRPORTS;
    numFlights = NUM_FLIGHTS;
    adjList = new AirportList[numAirports];
    int numInitialized = 0;
    fstream file("Users/user/Desktop/routes.csv");
    for (int i = 0; i < numFlights; i++) { //read file and add edges
        string airline;
        string source;
        string destination;
        getline(file, airline, ',');
        getline(file, source, ',');
        getline(file, destination, '\n');
        addFlight(source, destination, numInitialized);
    }
}

FlightNetwork::~FlightNetwork() { //traverse and free memory associated with every node
    delete[] adjList;
}

void FlightNetwork::addFlight(string source, string destination, int &numInitialized) {
    for (int i = 0; i < numInitialized; i++) { //avoid multiple edges
        if (adjList[i].getHead() != NULL && adjList[i].getHead()->getName() == source) {
            if (!adjList[i].hasFlightTo(destination)) {
                adjList[i].enqueueAirport(new Airport(destination, ""));
            }
            return;
        }
    }
    adjList[numInitialized].enqueueAirport(new Airport(source, ""));
    adjList[numInitialized].enqueueAirport(new Airport(destination, ""));
    numInitialized++;
}

AirportList FlightNetwork::getAdjs(string airport) { //return adjacent airports of parameter
    for (int i = 0; i < numAirports; i++) {
        if (adjList[i].getHead() != NULL && adjList[i].getHead()->getName() == airport) {
            return adjList[i];
        }
    }
    return AirportList();
}

bool FlightNetwork::checkDirectFlight(string source, string destination) {
    AirportList adjsOfSource = getAdjs(source);
    if (adjsOfSource.getHead() != NULL) {
        return adjsOfSource.hasFlightTo(destination);
    }
    return false;
}

void FlightNetwork::printDirectlyAccessibleAirports(string source) {
    AirportList adjsOfSource = getAdjs(source);
    if (adjsOfSource.getHead() != NULL) { //print adjacent airports if any
        adjsOfSource.printAdjAirports();
    } else {
        cout << "No directly accessible airports found.\n";
    }
}

bool FlightNetwork::isVisited(string toCheck, string visited[], int numVisited) {
    for (int i = 0; i < numVisited; i++) { //search the array
        if (visited[i] == toCheck) {
            return true;
        }
    }
    return false;
}

void FlightNetwork::setVisited(string toSet, string visited[], int &numVisited) {
    visited[numVisited] = toSet; //insert to array
    numVisited++;
}

bool FlightNetwork::checkFlightPathHelper(string source, string destination, string visited[], int &numVisited) {
    setVisited(source, visited, numVisited);
    if (source == destination) { //base case
        return true;
    }
    AirportList adjsOfSource = getAdjs(source);
    if (adjsOfSource.getHead() != NULL) {
        Airport* temp = adjsOfSource.getHead()->getNext();
        while (temp != NULL) {
            if (!isVisited(temp->getName(), visited, numVisited)) { //DFS - search a path to destination for adjacents
                if (checkFlightPathHelper(temp->getName(), destination, visited, numVisited)) {
                    return true;
                }
            }
            temp = temp->getNext();
        }
    }
    return false;
}

bool FlightNetwork::checkFlightPath(string source, string destination) {
    string visited[numAirports];
    int numVisited = 0;
    return checkFlightPathHelper(source, destination, visited, numVisited);
}

void FlightNetwork::printBestFlightPath(string source, string destination) { //BFS
    string visited[numAirports];
    int numVisited = 0;
    AirportList queue; //AirportList used as a queue
    queue.enqueueAirport(new Airport(source, source));
    setVisited(source, visited, numVisited);
    while (queue.getHead() != NULL) { //not empty
        Airport* head = queue.dequeuAirport();
        if (head->getName() == destination) {
            cout << "Shortest path from " + source + " to " + destination << " is: <" << head->getPath() << ">\n";
            return;
        }
        AirportList adjsOfHead = getAdjs(head->getName());
        if (adjsOfHead.getHead() != NULL) {
            Airport* temp = adjsOfHead.getHead()->getNext();
            while (temp != NULL) {
                if (!isVisited(temp->getName(), visited, numVisited)) {
                    queue.enqueueAirport(new Airport(temp->getName(), head->getPath() + " " + temp->getName()));
                    setVisited(temp->getName(), visited, numVisited);
                }
                temp = temp->getNext();
            }
        }
    }
    cout << "There is no path from " + source + " to " + destination << "." << endl;
}

void FlightNetwork::printDesiredFlightPaths(string source, string destination, int numStops) { //k shortest path routing
    cout << "Paths from " + source + " to " + destination << " with at most " << numStops << " stops are:" << endl;
    bool noSuchPath = true;
    Queue<AirportList> pathQueue;
    AirportList initialPath;
    initialPath.enqueueAirport(new Airport(source, ""));
    pathQueue.enqueue(initialPath);
    while (!pathQueue.isEmpty()) {
        AirportList currentPath;
        pathQueue.dequeue(currentPath);
        Airport* currentAirport = currentPath.getTail();
        if (currentAirport->getName() == destination) {
            currentPath.printAll();
            noSuchPath = false;
        }
        int currNumStops = currentPath.getSize() - 1;
        AirportList adjsOfHead = getAdjs(currentAirport->getName());
        if (adjsOfHead.getHead() != NULL) {
            Airport* temp = adjsOfHead.getHead()->getNext();
            while (temp != NULL) {
                if (!currentPath.contains(temp->getName()) && currNumStops + 1 <= numStops) { //check whether the current path contains the airport
                    AirportList newPath(currentPath);
                    newPath.enqueueAirport(new Airport(temp->getName(), temp->getPath()));
                    pathQueue.enqueue(newPath);
                } //update and enqueue the new path
                temp = temp->getNext();
            }
        }
    }
    if (noSuchPath) {
        cout << "There is no such path." << endl;
    }
}

//implementation of FlightNetwork class ends

//implementation of AirportList class starts

AirportList::AirportList() { //default constuctor
    head = NULL;
}

AirportList::AirportList(const AirportList &other) {
    size = other.size;
    Airport* temp = other.head;
    if (temp == NULL) {
        head = NULL;
    } else {
        head = new Airport(temp->getName(), temp->getPath());
        Airport* current = head;
        while (temp->getNext() != NULL) {
            temp = temp->getNext();
            Airport* newNode = new Airport(temp->getName(), temp->getPath());
            current->setNext(newNode);
            current = current->getNext();
        }
        current->setNext(NULL);
    }
}

Airport* AirportList::getHead() {
    return head;
}

Airport* AirportList::dequeuAirport() {
    if (head != NULL) { //if the list is not empty
        Airport* toReturn = head;
        head = head->getNext(); //update head to be the next
        size--;
        return toReturn;
    }
    return NULL;
}

void AirportList::enqueueAirport(Airport* toEnqueue) {
    if (head == NULL) { //if the list is empty
        head = toEnqueue;
    } else {
        Airport* temp = head; //insert the new airport to the end
        while (temp->getNext() != NULL) {
            temp = temp->getNext();
        }
        temp->setNext(toEnqueue);
    }
    size++;
}

bool AirportList::hasFlightTo(string destination) {
    if (head != NULL) { //search for destination in the airports connected to head
        Airport* temp = head->getNext();
        while (temp != NULL) {
            if (temp->getName() == destination) {
                return true;
            }
            temp = temp->getNext();
        }
    }
    return false;
}

bool AirportList::contains(string airport) {
    if (head != NULL) {
        Airport* temp = head;
        while (temp != NULL) {
            if (temp->getName() == airport) {
                return true;
            }
            temp = temp->getNext();
        }
    }
    return false;
}

void AirportList::printAdjAirports() {
    if (head != NULL) { //print airports connected to the head
        cout << "Airports directly accessible from " << head->getName() << " by the specified airlines are:\n";
        Airport* temp = head->getNext();
        bool hasNoAdjAirport = true;
        while (temp != NULL) {
            cout << temp->getName() << endl;
            temp = temp->getNext();
            hasNoAdjAirport = false;
        }
        if (hasNoAdjAirport) {
            cout << "No directly accessible airports found.\n";
        }
    }
}

void AirportList::printAll() {
    cout << "< ";
    if (head != NULL) { //print airports connected to the head
        Airport* temp = head;
        while (temp != NULL) {
            cout << temp->getName() << " ";
            temp = temp->getNext();
        }
    }
    cout << ">\n";
}

int AirportList::getSize() {
    return size;
}

Airport* AirportList::getTail() {
    if (head != NULL) {
        Airport* temp = head;
        while (temp->getNext() != NULL) {
            temp = temp->getNext();
        }
        return temp;
    }
    return NULL;
}

//implementation of AirportList class ends

//implementation of Airport class starts

Airport::Airport(string name, string path) { //constructor
    this->name = name;
    this->path = path;
    next = NULL;
}

string Airport::getName() { //accessors and modifiers
    return name;
}

string Airport::getPath() {
    return path;
}

Airport* Airport::getNext() {
    return next;
}

void Airport::setName(string name) {
    this->name = name;
}

void Airport::setPath(string path) {
    this->path = path;
}

void Airport::setNext(Airport* toSet) {
    this->next = toSet;
}

//implementation of Airport class ends

//implementation of Node class starts

template<class ItemType>
Node<ItemType>::Node() {
    next = NULL;
}

template<class ItemType>
Node<ItemType>::Node(const ItemType &item) {
    this->item = item;
    next = NULL;
}

template<class ItemType>
Node<ItemType>::Node(const ItemType &item, Node<ItemType>* next) {
    this->item = item;
    this->next = next;
}

template<class ItemType>
void Node<ItemType>::setItem(const ItemType &item) {
    this->item = item;
}

template<class ItemType>
void Node<ItemType>::setNext(Node<ItemType>* next) {
    this->next = next;
}

template<class ItemType>
ItemType Node<ItemType>::getItem() const{
    return item;
}

template<class ItemType>
Node<ItemType>* Node<ItemType>::getNext() const {
    return next;
}

//implementation of Node class ends

//implementation of Queue class starts

template<class ItemType>
Queue<ItemType>::Queue() {
    head = NULL;
    tail = NULL;
}

template<class ItemType>
bool Queue<ItemType>::isEmpty() const{
    return head == NULL;
}

template<class ItemType>
void Queue<ItemType>::enqueue(const ItemType &item) {
    Node<ItemType>* toEnqueue = new Node<ItemType>(item);
    if (isEmpty()) {
        head = toEnqueue;
    } else {
        tail->setNext(toEnqueue);
    }
    tail = toEnqueue;
}

template<class ItemType>
void Queue<ItemType>::dequeue(ItemType &dequedItem) {
    if (!isEmpty()) {
        Node<ItemType>* toDelete = head;
        if (head == tail) {
            head = NULL;
            tail = NULL;
        } else {
            head = head->getNext();
        }
        toDelete->setNext(NULL); //safe programming
        dequedItem = toDelete->getItem();
        delete toDelete; //avoid memory leak
    }
}

//implementation of Queue class ends


