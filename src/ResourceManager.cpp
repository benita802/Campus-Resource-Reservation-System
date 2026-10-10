#include "../include/ResourceManager.h"
#include <fstream>
#include <iostream>

using namespace std;

// Loads resource information from a text file into the resource vector
void ResourceManager::loadResources(string filename) {
    ifstream file(filename);

    if (!file) {
        cout << "Error: Could not open resource file." << endl;
        return;
    }

    string id;
    string name;
    string type;
    string status;

    while (getline(file, id, '|') &&
           getline(file, name, '|') &&
           getline(file, type, '|') &&
           getline(file, status)) {

        resources.push_back(
            Resource(id, name, type, status == "Available")
        );
    }

    file.close();
}

// Displays all resources in the vector
void ResourceManager::displayResources() {
    cout << "\n--- All Resources ---" << endl;

    for (const Resource& resource : resources) {
        cout << "ID: " << resource.getResourceID() << endl;
        cout << "Name: " << resource.getResourceName() << endl;
        cout << "Type: " << resource.getResourceType() << endl;

        if (resource.isAvailable()) {
            cout << "Status: Available" << endl;
        }
        else {
            cout << "Status: Unavailable" << endl;
        }

        cout << "--------------------" << endl;
    }
}

// Displays the availability status of each resource
void ResourceManager::displayAvailability() {
    cout << "\n--- Resource Availability ---" << endl;

    for (const Resource& resource : resources) {
        cout << resource.getResourceID()
             << " - "
             << resource.getResourceName()
             << ": ";

        if (resource.isAvailable()) {
            cout << "Available" << endl;
        }
        else {
            cout << "Unavailable" << endl;
        }
    }
}

// Merge sort process
void ResourceManager::sortResourcesByName(){
    if (resources.size() >1){
        mergeSort(0, resources.size() -1);
    
    }
}

void ResourceManager::mergeSort(int left, int right){
    if (left < right) {
        int mid = (left + right) /2;
        mergeSort(left, mid);
        mergeSort(mid+1, right);

        merge(left, mid, right);
    }
}

void ResourceManager::merge(int left, int mid, int right){
    vector<Resource> temp;

    int i = left;
    int j = mid +1;

    while (i <= mid&& j <= right){
        if (resources[i].getResourceName() <= resources[j].getResourceName()){
            temp.push_back(resources[i]);
            i++;
        }
        else{
            temp.push_back(resources[j]);
            j++;

        }

    }

    while (i <= mid){
        temp.push_back(resources[i]);
        i++;
    }
    while (j <= right){
        temp.push_back(resources[j]);
        j++;
    }

    for (int k = 0; k < temp.size(); k++) {
        resources[left + k] = temp[k];
    }
    vector<Resource>& ResourceManager::getAllResources() const {
    return resources;
}

}