#include <iostream>
#include "ReservationManager.h"
#include "Resource.h"
#include "WaitingList.h"
#include <iomanip>


using namespace std;

int main () {

    ReservationManager reservation;
    int choice = 0;
    
    do {
    cout << "====== Campus Resourse Reservation System ======"  << endl; 
    cout << " 1: View Resources       " << endl;
    cout << " 2: Create Reservation   " << endl;
    cout << " 3: Cancel Reservation   " << endl;
    cout << " 4: View Waiting Lists   " << endl;
    cout << " 5: Undo Cancellation    " << endl;
    cout << " 6: Search Reservations  " << endl;
    cout << " 7: Sort Resources       " << endl;
    cout << " 8: Generate Report      " << endl;
    cout << " 9: Exit                 " << endl;
    
    cout << "Enter Choice: " << endl;
    cin >> choice;

    switch (choice) {
        case 1:
            reservation.loadResources();
            reservation.displayResources();
            break;
        case 2:
            reservation.createReservation();
            break;
        case 3:
           reservation.cancelReservation();
            break;
        case 4:
            reservation.displayWaitingList();
            break;
        case 5:
             reservation.restoreLastCancelled();
            break;
        case 6:
            reservation.findReservation();
            break;
        //case 7:
         //   reservation.();
       //     break;
       // case 8:
          //  reservation.();
           // break;   
        //case 9:
           // reservation.();
           // break;                   
        default:
            cout << "Invalid menu option. Please enter 1-9." <<endl;
            break;
        }

        cout << endl;

    } while (choice != 9);


    }
