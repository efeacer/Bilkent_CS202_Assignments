/*
 * Title: Hashing and Graphs
 * Author: EFE ACER
 * ID: 21602217
 * Section: 3
 * Assignment: 4
 * Description: This header file involves declerations for the public and private interfaces
 *              of FlightNetwork class and other helper classes that it uses. Formal comments
 *              of the functions can be found below.
 */

#include <string> //string

using namespace std;

/*
 * A class to represent each vertex in the FlightNetwork graph
 */
class Airport {
private: //private interface
    //properties
    string name; //airport name
    string path; //a path to the airport
    Airport* next; //an airport adjacent to this airport
public: //public interface
    /*
     * Constructor of an Airport
     * @param name The name of the airport.
     * @param path The sequence of airports that constructs a path to this airport.
     */
    Airport(string name, string path);
    /*
     * Accessor method for the name of the airport.
     * @return The name of the airport.
     */
    string getName();
    /*
     * Accessor method for the path to the airport.
     * @return The path to the airport.
     */
    string getPath();
    /*
     * Accessor method for the airport adjacent to this airport.
     * @return The airport adjacent to this airport.
     */
    Airport* getNext();
    /*
     * Setter method for the name of the airport
     * @param name The name of the airport to be set.
     */
    void setName(string name);
    /*
     * Setter method for the path to the airport
     * @param name The string representing the path to the airport that will be set.
     */
    void setPath(string path);
    /*
     * Setter method for the airport adjacent to this airport
     * @param name The name of the adjacent airport to be set.
     */
    void setNext(Airport* toSet);
};

/*
 * A class that helps FlightNetwork graph to be stored in an adjacency list structure. It also
 * acts as a queue in certain algorithms.
 */
class AirportList {
private: //private interface
    //properties
    int size;
    Airport* head; //a pointer to the beginning of the list (List consists of pointers to Airport objects)
public: //public interface
    /*
     * Default constructor of an AirportList, initializes head pointer to NULL
     */
    AirportList();
    /*
     * Deep copy constructor of the AirportList class.
     * @param other The other object that will be deep copied.
     */
    AirportList(const AirportList &other);
    /*
     * Accessor method for the head pointer.
     * @return The head pointer of the list, NULL if the list is empty
     */
    Airport* getHead();
    /*
     * Dequeues the head of the list by pointer updates, helps the list to act as a queue.
     * @return The head pointer of the list.
     */
    Airport* dequeuAirport();
    /*
     * Enqueues an airport to the end of the list, helps the list to act as a queue.
     * @param toEnqueue The airport that will be inserted to the end of the list.
     */
    void enqueueAirport(Airport* toEnqueue);
    /*
     * Checks whether the destination airport is one of the airports connected to the head or not.
     * @param destination The name of the airport whose connection to the head will be tested.
     * @return True if there is a connection between head and destination, false otherwise.
     */
    bool hasFlightTo(string destination);
    /*
     * Prints all airports connected to the head airport.
     */
    void printAdjAirports();
    /*
     * Checks the presence of an airport in the list.
     * @param airport The airport to be searched.
     * @return True if the airport is in the list, false otherwise.
     */
    bool contains(string airport);
    /*
     * Prints the items of the entire list.
     */
    void printAll();
    /*
     * Returns the current size of the list.
     * @return The size of the list.
     */
    int getSize();
    /*
     * Finds and returns the tail of the list.
     * @return The tail pointer.
     */
    Airport* getTail();
};

/*
 * The class representing FlightNetwork graph, includes methods to perform traversals and searches in the
 * graph.
 */
class FlightNetwork {
private: //private interface
    //properties
    int numAirports; //number of vertices
    int numFlights; //number of edges to read
    AirportList* adjList; //the adjacency list holding the adjacency relations between the vertices.
    /*
     * Addes a directed edge to the FlightNetwork graph by updating the adjacency list, does not allow multiple
     * edges between two vertices.
     * @param source The source vertex.
     * @param destination The destination vertex.
     * @param numInitialized A reference to the variable holding the number of vertices added to the adjacency list.
     */
    void addFlight(string source, string destination, int &numInitialized);
    /*
     * Returns the AirportList containing the adjacent airports of the parameter airport.
     * @param airport The airport whose adjacent airports will be returned.
     */
    AirportList getAdjs(string airport);
    /*
     * Checks whether a given airport is in the array of previously visited airports or not.
     * @param toCheck Airport that will be checked to be visited or not.
     * @param visited[] An array of airports, an airport being in this array means that it is visited.
     * @param numVisited The size of the array of visited airports.
     * @return True if toCheck is in the array, false otherwise.
     */
    bool isVisited(string toCheck, string visited[], int numVisited);
    /*
     * Adds a given airport to the array of previously visited airports.
     * @param toSet The airport that will be added to the array of visited airports.
     * @param visited[] An array of airports, an airport being in this array means that it is visited.
     * @param numVisited A reference to the variable holding the size of the array of visited airports.
     */
    void setVisited(string toSet, string visited[], int &numVisited);
    /*
     * Checks if there are any flight paths from the source airport to the destination airport by using DFS. Acts as
     * a helper method for a method in the public interface.
     * @param source The source airport
     * @param destination The destination airport.
     * @param visited[] An array of airports, an airport being in this array means that it is visited.
     * @param numVisited A reference to the variable holding the size of the array of visited airports.
     * @return True if the source airport is connected to the destination airport by some flight path, false otherwise.
     */
    bool checkFlightPathHelper(string source, string destination, string visited[], int &numVisited);
public: //public interface
    /*
     * The default constructor of the FlightNetwork class. Constructs a graph by reading the data inside a
     * specific file. The constructed graph is stored in an adjacency list structure without multiple edges
     * between the same two vertices.
     */
    FlightNetwork();
    /*
     * Destructor of the FlightNetwork class. Traverses the adjacency list and frees the memory associated with
     * the vertices.
     */
    ~FlightNetwork();
    /*
     * Checks if there are any direct flights from the source airport to the destination airport by looking at
     * the list of airports adjacent to the source airport.
     * @param source The source airport.
     * @param destination The destination airport.
     * @return True if destination is directly accessible from source, false otherwise.
     */
    bool checkDirectFlight(string source, string destination);
    /*
     * Finds and prints the list of airports adjacent to the parameter airport, source.
     * @param source The airport whose adjacent airports will be printed.
     */
    void printDirectlyAccessibleAirports(string source);
    /*
     * Checks if there are any flight paths from the source airport to the destination airport by using a helper
     * method that implements DFS.
     * @param source The source airport
     * @param destination The destination airport.
     * @return True if the source airport is connected to the destination airport by some flight path, false otherwise.
     */
    bool checkFlightPath(string source, string destination);
    /*
     * Finds and prints the flight path from the source airport to the destination airport with the minimum
     * number of stops. Performs a DFS to accomplish that.
     * @param source The source airport
     * @param destination The destination airport.
     */
    void printBestFlightPath(string source, string destination);
    /*
     * Finds and prints all of the flight paths with numStops or lower number of stops from the source airport to the
     * destination airport. Uses the k shortest path routing algorithm to accomplish that. The method is implemented
     * without STL, only linear data structures such as an adjacency list and a queue(linked-list based); so the runtime
     * is a little slower than the ideal implementation.
     * @param source The source airport
     * @param destination The destination airport.
     * @param numStops The maximum number of stops allowed in a flight path.
     */
    void printDesiredFlightPaths(string source, string destination, int numStops);
};

/*
 * A generic Node class for the Queue class used in part e.
 */
template<class ItemType>
class Node {
private: //private interface
    ItemType item;
    Node<ItemType>* next;
public: //public interface
    /*
     * The default constructor.
     */
    Node();
    /*
     * Constructs a Node with the given item.
     * @param item The item that the constructed Node will carry.
     */
    Node(const ItemType &item);
    /*
     * Constructs a Node with the given item and the next pointer.
     * @param item The item that the constructed Node will carry.
     * @param next The next pointer that the constructed Node will have.
     */
    Node(const ItemType &item, Node<ItemType>* next);
    /*
     * Sets the parameter item to be the objects item.
     * @param item The item that the Node will carry.
     */
    void setItem(const ItemType &item);
    /*
     * Sets the next pointer to be the specified pointer.
     * @param next The next pointer that the Node will have.
     */
    void setNext(Node<ItemType>* next);
    /*
     * Accessor method for the item field.
     * @return The item carried by the Node.
     */
    ItemType getItem() const;
    /*
     * Accessor method for the next pointer.
     * @return The address pointed by the Node.
     */
    Node<ItemType>* getNext() const;
};

/*
 * A linked base Queue structure to use in part e
 */
template<class ItemType>
class Queue {
private:
    Node<ItemType>* head; //beginning pointer
    Node<ItemType>* tail; //end pointer
public:
    /*
     * The deafault constructor.
     */
    Queue();
    /*
     * Checks for the head pointer being valid, hence tells whether the queue is empty or not.
     * @return True if the queue is empty false otherwise.
     */
    bool isEmpty() const;
    /*
     * Enqueues the given item.
     * @param item The item to be inserted to the end of the queue.
     */
    void enqueue(const ItemType &item);
    /*
     * Dequeues an item from the queue. (FIFO)
     * @param dequedItem A reference to the variable having the dequeued item.
     */
    void dequeue(ItemType &dequedItem);
};





