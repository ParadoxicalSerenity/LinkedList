#include <iostream>
#include "LinkedList.h"

using namespace std;

int main() {
    const int index_offset = 1; // for loops that start at 0
    LinkedList list = LinkedList();

    cout << "Creating a list..." << std::endl;
    int totalItems = 7;

    for (auto i = 0; i <= totalItems; i++) list.append("");

    cout << "List current size: " << list.getSize() << endl;

    list.dumpState();

    cout << "Position 2 accessed with at: " << list.at(2) << std::endl;
    cout << "Position 2 accessed with []: " << list[2] << std::endl;

    cout << "List current size: " << list.getSize() << endl;
    list.remove(2);
    cout << "Position 2 deleted with remove(index) showing new position two: " << list[2] << std::endl;
    cout << "List current size: " << list.getSize() << endl;

    list.dumpState();

    cout << "Inserting after position 2." << std::endl;

    list.insertAfter(2,"");

    list.dumpState();

    cout << "Inserting before position 2." << std::endl;

    list.insertBefore(2,"");

    list.dumpState();



    cout << "Freeing list using remove()" << std::endl;

    for (auto i = 0; i <= totalItems; i++) list.remove();

    cout << "List current size: " << list.getSize() << endl;
    cout << "Item currently in memory: " <<list[0];
    return 0;
}
