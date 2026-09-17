#include "Reservation.h"
#include <iostream>
#include <string>

using namespace std;


Reservation::Reservation {
    int reservationID
    int studentID
    int resourceID
    const string& reservationDate
    const string& studentName 

}

    // Setters
    void Reservation::setStudentName(const string& name) {
        studentName = name;
    }
    void Reservation::setReservationDate(const string& date) {
        reservationDate = date;
    }

    // Getters
    int Reservation::getReservationID() const {
        return reservationID;
    }

    int Reservation::getStudentID() const {
        return studentID;
    }

    string Reservation::getStudentName() const {
        return studentName;
    }

    int Reservation::getResourceID() const {
        return resourceID;
    }

    string Reservation::getReservationDate() const {
        return reservationDate;
    }