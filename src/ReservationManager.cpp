#include "ReservationManager.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

//Construct.
ReservationManager::ReservationManager() {
    head = nullptr;
}

// Reservations from file.
void ReservationManager::loadReservations(const string& filename) {

    ifstream file(filename);

    if (!file.is_open()) {
        cout << "Could not open reservation file." << endl;
        return;
    }

    string line;

    while (getline(file, line)) {

        stringstream ss(line);

        int resID;
        int stuID;
        string resrcID;

        string stuName;
        string date;
        string value;

        getline(ss, value, '|');
        resID = stoi(value);

        getline(ss, value, '|');
        stuID = stoi(value);

        getline(ss, stuName, '|');

        getline(ss, value, '|');
        resrcID = stoi(value);

        getline(ss, date);

        Reservation r(resID, stuID, stuName, resrcID, date);

        createReservation(r);
    }

    file.close();
}

// Save active reservations to file.
void ReservationManager::saveReservations(const string& filename) const {
    ofstream file(filename);
     if (!file.is_open()) {
        cout << "Couldn't open the reservation file." << endl;
        return;
    }

    Node* current = head;

    while (current != nullptr) {

        file << current->reservation.getReservationID() << "|"
              << current->reservation.getStudentID() << "|"
              << current->reservation.getStudentName() << "|"
              << current->reservation.getResourceID() << "|"
              << current->reservation.getReservationDate()
              << endl;
        current = current->next;
    }

    file.close();
}


// Create reservation into list.
bool ReservationManager::createReservation(const Reservation& r) {
    if (reservationExists(r.getReservationID())) {
        cout << "Reservation ID already exists.\n";
        return false;
    }

    // Create new node
    Node* newNode = new Node(r);

    // If the list is empty
    if (head == nullptr) {
        head = newNode;
    }

    // Otherwise insert at the end
    else {

        Node* current = head;

        while (current->next != nullptr) {
            current = current->next;
        }

        current->next = newNode;
    }

    return true;
}



// Cancel reservation
bool ReservationManager::cancelReservation(int reservationID) {
    Node* current = head;
    Node* previous = nullptr;

    while (current != nullptr) {
        if (current->reservation.getReservationID() == reservationID) {
            // Store cancelled reservation in stack.
            cancelledStack.push(current->reservation);

            // Removing the first node.
            if (previous == nullptr) {
                head = current->next;
            }

            // Removing node.
            else {
                previous->next = current->next;
            }

            delete current;

            return true;
        }
        previous = current;
        current = current->next;
    }

    return false;
}


// Restore most recently cancelled.
bool ReservationManager::restoreLastCancelled() {
    if (cancelledStack.empty()) {
        cout << "No cancelled reservations to restore.\n";
        return false;
    }

    Reservation r = cancelledStack.top();

    if (createReservation(r)) {
        cancelledStack.pop();
        return true;
    }

    return false;
}


// Display the reservations.
void ReservationManager::displayActiveReservations() const {

    cout << "\n--- Active Reservations ---\n";

    if (head == nullptr) {
        cout << "No active reservations.\n";
        return;
    }

    Node* current = head;

    while (current != nullptr) {

        cout << "Reservation ID: " << current->reservation.getReservationID() << endl;
        cout << "Student ID: " << current->reservation.getStudentID() << endl;
        cout << "Student Name: " << current->reservation.getStudentName() << endl;
        cout << "Resource ID: " << current->reservation.getResourceID() << endl;
        cout << "Reservation Date: " << current->reservation.getReservationDate() << endl;
        cout << "---------------------------\n";

        // Move to next.
        current = current->next;
    }
}


// Cancellation history.
void ReservationManager::displayCancellationHistory() const {
    stack<Reservation> temp = cancelledStack;

    cout << "\n--- Cancellation History ---\n";

    if (temp.empty()) {
        cout << "No cancellation history.\n";
        return;
    }

    while (!temp.empty()) {

        Reservation r = temp.top();

        cout << "Reservation ID: " << r.getReservationID() << endl;
        cout << "Student ID: " << r.getStudentID() << endl;
        cout << "Student Name: " << r.getStudentName() << endl;
        cout << "Resource ID: " << r.getResourceID() << endl;
        cout << "Reservation Date: " << r.getReservationDate() << endl;
        cout << "---------------------------\n";

        temp.pop();
    }
}


// Reservation by ID.
Reservation* ReservationManager::findReservation(int reservationID) {

    Node* current = head;

    while (current != nullptr) {
        if (current->reservation.getReservationID() == reservationID) {
            return &(current->reservation);
        }

        current = current->next;
    }

    return nullptr;
}


// Check if reservation already exists.
bool ReservationManager::reservationExists(int reservationID) const {

    Node* current = head;

    while (current != nullptr) {
        if (current->reservation.getReservationID() == reservationID) {
            return true;
        }

        current = current->next;
    }

    return false;
}
