#include <iostream>
#include <algorithm>
#include "ReservationManager.h"
#include "Resource.h"
#include "ResourceManager.h"
#include "WaitingList.h"
#include <iomanip>


using namespace std;

int main () {

    ReservationManager reservation;
    ResourceManager resource;
    WaitingList waitingList;

    int choice = 0;

    // Load information when the program starts
    resource.loadResources("data/resources.txt");
    reservation.loadReservations("data/reservations.txt");
    
    do {
    cout << "====== Campus Resourse Reservation System ======"  << endl; 
    cout << " 1: View Resources       " << endl;
    cout << " 2: Create Reservation   " << endl;
    cout << " 3: Cancel Reservation   " << endl;
    cout << " 4: Add Student to WaitList  " << endl;
    cout << " 5: Remove Student from WaitList " << endl;
    cout << " 6: View Waiting Lists   " << endl;
    cout << " 7: Undo Cancellation    " << endl;
    cout << " 8: Search Reservations  " << endl;
    cout << " 9: Sort Resources       " << endl;
    cout << " 10: Generate Report      " << endl;
    cout << " 11: Exit                 " << endl;
    
    cout << "Enter Choice: " << endl;
    cin >> choice;

    switch (choice) {
        case 1:
            resource.displayResources();
            break;

        case 2: {
           // createReservation() needs a Reservation object.
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
           //  cancelReservation() needs a reservation ID.
                int reservationID;

                cout << "Enter Reservation ID to cancel: ";
                cin >> reservationID;

                if (reservation.cancelReservation(reservationID)) {
                    cout << "Reservation cancelled successfully." << endl;
                } else {
                    cout << "Reservation not found." << endl;
                }

            break;
        }

        case 4: {
            string resourceID;
            string studentID;

            cout << "Enter Resource ID: ";
            cin >> resourceID;

            cout << "Enter Student ID: ";
            cin >> studentID;

            waitingList.addStudent(resourceID, studentID);

            cout << "Student added to waiting list." << endl;
            break;
        } 
        

        case 5: {
            string resourceID;

            cout << "Enter Resource ID: ";
            cin >> resourceID;

            waitingList.removeStudent(resourceID);

            break;
        }

        case 6: {
             waitingList.displayWaitingList();
            break;
        }

        case 7:
             if (reservation.restoreLastCancelled()){
                    cout << "Cancellation undone successfully." << endl;
                }
                else{
                    cout<<" Undo failed." << endl;
                }
          break;


        case 8: 

            int reservationID;

                cout << "Enter Reservation ID to search: ";
                cin >> reservationID;

                Reservation* found =
                    reservation.linearSearch(reservationID);

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
        

        case 9:
           resource.sortResourcesByName(); 
                resource.displayResources();
            break;  

        case 10: {
            cout << "======== Sytem Report ==========" << endl;

            // Active Reservations
            cout << "-------- Active Reservations --------" << endl;
            reservation.displayActiveReservations();

            // Resources Utilization
            cout << "--- Resource Utilization ---" << endl;

            auto utilization = reservation.countReservationsPerResource();
            const auto& allResources = resource.getAllResources();

            for (const Resource& res : allResources) {
            string id = res.getResourceID();
            int count = utilization[id];  // 0 if not present

            cout << "Resource ID: " << id
             << " | Name: " << res.getResourceName()
             << " | Reservations: " << count << endl;
             }

            cout << "--- Most Requested Resources ---" << endl;

            vector<pair<string,int>> sorted(utilization.begin(), utilization.end());

            sort(sorted.begin(), sorted.end(),
            [](auto& a, auto& b) { return a.second > b.second; });

            for (auto& entry : sorted) {
            cout << "Resource ID: " << entry.first
            << " | Requests: " << entry.second << endl;
}           
            
            //waiting-list data maintained by your system.
            cout << "------ Waiting List------- " << endl;
            waitingList.displayWaitingList();
            auto waitingStats = waitingList.countWaitingPerResource();

            for (const Resource& res : allResources) {
                string id = res.getResourceID();

                cout << "Resource ID: " << id << " | Students Waiting: " << waitingStats[id] << endl;
}
            break;
        } 
        

        case 11: 
                reservation.saveReservations("data/reservations.txt");
                cout << "Reservations saved." << endl;
                cout << "Exiting program." << endl;
                break;           

        default:
            cout << "Invalid menu option. Please enter 1-11." <<endl;
            break;
        }

        cout << endl;

    } while (choice != 11);

        return 0;

    }
