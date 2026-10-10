#ifndef WAITING_LIST_H
#define WAITING_LIST_H

#include <queue>
#include <string>
#include <map>

using namespace std;

// Manages students waiting for campus resources

class WaitingList {
private:
    map<string, queue<string>> students;

public:
    void addStudent(string& resourceID, string& studentID);
    void removeStudent(string& resourceID);
    void displayWaitingList() const;
    map<string, int> countWaitingPerResource() const;
};

#endif // WAITING_LIST_H  

