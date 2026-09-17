#include <iostream>
#include <string>
#include "ReservationManager.h"
#include "ResourceManager.h"
#include "WaitingList.h"

using namespace std;

int main() {

    ReservationManager reservation;
    ResourceManager resource;
    WaitingList waitingList;

    int choice = 0;

    // Load information when the program starts
    resource.loadResources("data/resources.txt");
    reservation.loadReservations("data/reservations.txt");

    do {
        cout << "====== Campus Resource Reservation System ======" << endl;
        cout << " 1: View Resources       " << endl;
        cout << " 2: Create Reservation   " << endl;
        cout << " 3: Cancel Reservation   " << endl;
        cout << " 4: View Waiting Lists   " << endl;
        cout << " 5: Undo Cancellation    " << endl;
        cout << " 6: Search Reservations  " << endl;
        cout << " 7: Sort Resources       " << endl;
        cout << " 8: Generate Report      " << endl;
        cout << " 9: Exit                 " << endl;

        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice) {

            case 1:
                // FIXED: Resources belong to ResourceManager,
                // not ReservationManager.
                resource.displayResources();
                break;


            case 2: {
                // FIXED: createReservation() needs a Reservation object.
                int reservationID;
                int studentID;
                string studentName;
                string resourceID;
                string reservationDate;

                cout << "Enter Reservation ID: ";
                cin >> reservationID;

                cout << "Enter Student ID: ";
                cin >> studentID;

                cin.ignore();

                cout << "Enter Student Name: ";
                getline(cin, studentName);

                cout << "Enter Resource ID: ";
                getline(cin, resourceID);

                cout << "Enter Reservation Date: ";
                getline(cin, reservationDate);

                Reservation newReservation(
                    reservationID,
                    studentID,
                    studentName,
                    resourceID,
                    reservationDate
                );

                if (reservation.createReservation(newReservation)) {
                    cout << "Reservation created successfully." << endl;
                }
                else {
                    cout << "Reservation could not be created." << endl;
                }

                break;
            }


            case 3: {
                // FIXED: cancelReservation() needs a reservation ID.
                int reservationID;

                cout << "Enter Reservation ID to cancel: ";
                cin >> reservationID;

                if (reservation.cancelReservation(reservationID)) {
                    cout << "Reservation cancelled successfully." << endl;
                }
                else {
                    cout << "Reservation not found." << endl;
                }

                break;
            }


            case 4:
                // FIXED: Waiting list belongs to WaitingList,
                // not ReservationManager.
                waitingList.displayWaitingList();
                break;


            case 5:
                if (reservation.restoreLastCancelled()) {
                    cout << "Cancellation undone successfully." << endl;
                }
                else {
                    cout << "Unable to undo cancellation." << endl;
                }
                break;


            case 6: {
                // FIXED: findReservation() needs a reservation ID.
                int reservationID;

                cout << "Enter Reservation ID to search: ";
                cin >> reservationID;

                Reservation* found =
                    reservation.findReservation(reservationID);

                if (found != nullptr) {
                    cout << "\n--- Reservation Found ---" << endl;
                    cout << "Reservation ID: "
                         << found->getReservationID() << endl;
                    cout << "Student ID: "
                         << found->getStudentID() << endl;
                    cout << "Student Name: "
                         << found->getStudentName() << endl;
                    cout << "Resource ID: "
                         << found->getResourceID() << endl;
                    cout << "Reservation Date: "
                         << found->getReservationDate() << endl;
                }
                else {
                    cout << "Reservation not found." << endl;
                }

                break;
            }


            case 7:
                cout << "Sort Resources not implemented yet." << endl;
                break;


            case 8:
                reservation.displayActiveReservations();
                break;


            case 9:
                reservation.saveReservations("data/reservations.txt");
                cout << "Reservations saved." << endl;
                cout << "Exiting program." << endl;
                break;


            default:
                cout << "Invalid menu option. Please enter 1-9." << endl;
                break;
        }

        cout << endl;

    } while (choice != 9);

    return 0;
}
