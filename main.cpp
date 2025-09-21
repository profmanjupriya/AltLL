#include <iostream>
#include <string>
#include "linkedlist.h"

using namespace std;

// Simple function to print the list
void printList(LinkedList<string>& list) {
    cout << "List: ";
    int index = 0;
    list.forEach([&](const string& value, bool isLast){
        cout << "[" << index++ << ":" << value << "]";
        if (!isLast) cout << " -> ";
    });
    if (index == 0) cout << "empty";
    cout << endl;
}

void showMenu() {
    cout << "\n--- Linked List Menu ---\n";
    cout << "1. Append (add to end)\n";
    cout << "2. Add First (add to front)\n";
    cout << "3. Delete First\n";
    cout << "4. Delete Last\n";
    cout << "5. Delete At Index\n";
    cout << "6. Print List\n";
    cout << "0. Exit\n";
    cout << "Choose an option: ";
}

int main() {
    LinkedList<string> list;
    int choice;

    cout << "Welcome to the Linked List Demo!" << endl;

    do {
        showMenu();
        cin >> choice;

        if (choice == 1) {
            string val;
            cout << "Enter value: ";
            cin >> val;
            list.append(val);
        }
        else if (choice == 2) {
            string val;
            cout << "Enter value: ";
            cin >> val;
            list.addFirst(val);
        }
        else if (choice == 3) {
            list.deleteFirst();
        }
        else if (choice == 4) {
            list.deleteLast();
        }
        else if (choice == 5) {
            int index;
            cout << "Enter index: ";
            cin >> index;
            list.deleteAtIndex(index);
        }
        else if (choice == 6) {
            printList(list);
        }
        else if (choice == 0) {
            cout << "Goodbye!" << endl;
        }
        else {
            cout << "Invalid choice, try again." << endl;
        }

    } while (choice != 0);

    return 0;
}