/*
 * Title: Hashing and Graphs
 * Author: EFE ACER
 * ID: 21602217
 * Section: 3
 * Assignment: 4
 * Description: This file tests and demonstrates the methods of the FlightNetwork class.
 */

#include "FlightNetwork.h"
#include <iostream> //cin and cout

int main() {
    FlightNetwork flightNetwork;
    char option;
    string source;
    string destination;
    int numStops;
    cin >> option;
    if (option == 'a') {
        cin >> source >> destination;
        if (flightNetwork.checkDirectFlight(source, destination)) {
            cout << "There is a direct flight from " + source + " to " + destination << ".\n";
        } else {
            cout << "There is no direct flight from " + source + " to " + destination << ".\n";
        }
    } else if (option == 'b') {
        cin >> source;
        flightNetwork.printDirectlyAccessibleAirports(source);
    } else if (option == 'c') {
        cin >> source >> destination;
        if (flightNetwork.checkFlightPath(source, destination)) {
            cout << "There is a path from " + source + " to " + destination + ".\n";
        } else {
            cout << "There is no path from " + source + " to " + destination + ".\n";
        }
    } else if (option == 'd') {
        cin >> source >> destination;
        flightNetwork.printBestFlightPath(source, destination);
    } else if (option == 'e') {
        cin >> source >> destination >> numStops;
        flightNetwork.printDesiredFlightPaths(source, destination, numStops);
    }
    return 0;
}



