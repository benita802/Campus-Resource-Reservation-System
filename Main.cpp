#include <iostream>
#include "ReservationManager.h"
#include "ResourceManager.h"
#include "WaitingList.h"
#include <iomanip>
#include <string>

using namespace std;

int main() {

    ReservationManager reservation;
    ResourceManager resource;
    WaitingList waitingList;

    int choice = 0;

    // Load resources when program starts
    resource.loadResources("data/resources.txt");

    // Load existing reservations when program starts
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

            // View Resources
            case 1:
                resource.displayResources();
                break;


            // Create Reservation
            case 2: {
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


            // Cancel Reservation
            case 3: {
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


            // View Waiting List
            case 4:
                waitingList.displayWaitingList();
                break;


            // Undo Cancellation
            case 5:

                if (reservation.restoreLastCancelled()) {
                    cout << "Cancellation undone successfully." << endl;
                }
                else {
                    cout << "Unable to undo cancellation." << endl;
                }

                break;


            // Search Reservations
            case 6: {
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


            // Sort Resources
            case 7:
                // Sort function will be added when implemented
                cout << "Sort Resources not implemented yet." << endl;
                break;


            // Generate Report
            case 8:
                // Display active reservations for report
                reservation.displayActiveReservations();
                break;


            // Exit
            case 9:

                // Save reservations before program closes
                reservation.saveReservations("data/reservations.txt");

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
