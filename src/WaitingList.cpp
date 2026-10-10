#include "../include/WaitingList.h"
#include <iostream>

using namespace std;

void WaitingList::addStudent(string& resourceID,string studentID){
    students[resourceID].push(studentID); 
}

void WaitingList::removeStudent(string& resourceID){
    if (students[resourceID].empty()) {
        cout << "Waiting list is empty." <<endl;
        return;
    }

    cout << "Removing Student: " << students[resourceID].front() <<endl;
    students[resourceID].pop();
}
void WaitingList::displayWaitingList() const {
    if (students.empty()) {
        cout << "Waiting list is empty." << endl;
        return;
    }

    cout << "--- Waiting List ---" << endl;

    for (const auto& entry : students) {
        cout << "Resource " << entry.first << ":" << endl;

        queue<string> temp = entry.second;
        if (temp.empty()) {
            cout << "  (empty)" << endl;
            continue;
        }

        while (!temp.empty()) {
            cout << "  " << temp.front() << endl;
            temp.pop();
        }   
    }
} 
//Count stud waiting for each resource
map<string, int> WaitingList::countWaitingPerResource() const {

    map<string, int> counts;

    for (const auto& entry : students) {
        counts[entry.first] = entry.second.size();
    }

    return counts;
}
