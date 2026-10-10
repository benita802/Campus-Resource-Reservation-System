//Handles reservation operations|| CancellationHistory Manages stack operations.
#ifndef RESERVATION_MANAGER_H
#define RESERVATION_MANAGER_H

#include <stack>
#include <string>
#include "Reservation.h"

using namespace std;

class ReservationManager {

private:
    //Node for active reservations linked list
    struct Node {
        Reservation reservation;
        Node* next;

        Node(const Reservation& r) : reservation(r) {
            next = nullptr;
        }
    };

    Node* head;

    //Cancellation history.
    stack<Reservation> cancelledStack;

    //Check if reservation is already existent.
    bool reservationExists(int reservationID) const;

public:
    //Construct.
    ReservationManager();

    //Operations.
    void loadReservations(const string& filename);
    void saveReservations(const string& filename) const;


    bool createReservation(const Reservation& r);
    bool cancelReservation(int reservationID);
    bool restoreLastCancelled();

    void displayActiveReservations() const;
    void displayCancellationHistory() const;

    //Linear Search.
    Reservation* linearSearch(int reservationID);
};

#endif
