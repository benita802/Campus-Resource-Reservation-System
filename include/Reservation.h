//Stores reservation information.
#ifndef RESERVATION_H
#define RESERVATION_H

#include <string>
using namespace std;

class Reservation {

private:
    int reservationID;
    int studentID;
    string resourceID;
    string studentName;
    string reservationDate; // mm/dd/yyyy

public:
    // constructor
    Reservation(int reservationID,int studentID,const string& studentName,const string& resourceID,const string& reservationDate);

    // Setters
    void setStudentName(const string& name);
    void setReservationDate(const string& date);

    // Getters
    int getReservationID() const;
    int getStudentID() const;
    string getStudentName() const;
    string getResourceID() const;
    string getReservationDate() const;

};

#endif
