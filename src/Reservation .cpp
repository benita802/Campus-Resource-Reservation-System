#include "Reservation.h"
#include <iostream>
#include <string>

using namespace std;


Reservation::Reservation(int reservationID, int studentID, const string& studentName, const string& resourceID,const string& reservationDate) {

    this->reservationID = reservationID;
    this->studentID = studentID;
    this->studentName = studentName;
    this->resourceID = resourceID;
    this->reservationDate = reservationDate;
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

    string Reservation::getResourceID() const {
        return resourceID;
    }

    string Reservation::getReservationDate() const {
        return reservationDate;
    }
