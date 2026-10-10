#ifndef RESOURCE_MANAGER_H
#define RESOURCE_MANAGER_H

#include "Resource.h"
#include <vector>
#include <string>

using namespace std;

// Manages campus resource inventory
class ResourceManager {
private:
    vector<Resource> resources;

    void mergeSort(int left, int right);
    void merge(int left, int mid, int right);

public:
    void loadResources(string filename);
    void displayResources();
    void displayAvailability();
    void sortResourcesByName();
    const vector<Resource>& getAllResources() const;
};

#endif // RESOURCE_MANAGER_H
