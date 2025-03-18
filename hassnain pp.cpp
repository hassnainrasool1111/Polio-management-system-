#include <iostream>
using namespace std;

// Structure to store child details
struct Child {
    string name;
    int age;
    string parentContact;
    bool isVaccinated;
};


Child children[100];
int childCount = 0;

void registerChild() {
    if (childCount < 100) {
        cout << "Enter Child's Name: ";
        cin >> children[childCount].name;
        cout << "Enter Age: ";
        cin >> children[childCount].age;
        cout << "Enter Parent's Contact: ";
        cin >> children[childCount].parentContact;
        children[childCount].isVaccinated = false; 
        childCount++;
        cout << "Child Registered Successfully!\n";
    } else {
        cout << "Database is full!\n";
    }
}


void markVaccinated() {
    string name;
    cout << "Enter Child's Name: ";
    cin >> name;

    for (int i = 0; i < childCount; i++) {
        if (children[i].name == name) {
            children[i].isVaccinated = true;
            cout << "Child marked as Vaccinated!\n";
            return;
        }
    }
    cout << "Child Not Found!\n";
}

void showChildren() {
    cout << "\nList of Children:\n";
    for (int i = 0; i < childCount; i++) {
        cout << "Name: " << children[i].name << " | Age: " << children[i].age
             << " | Vaccinated: " << (children[i].isVaccinated ? "Yes" : "No") << "\n";
    }
}


int main() {
    int choice;
    do {
        cout << "\nPolio Management System\n";
        cout << "1. Register Child\n";
        cout << "2. Mark Vaccinated\n";
        cout << "3. Show Children\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: registerChild(); break;
            case 2: markVaccinated(); break;
            case 3: showChildren(); break;
            case 4: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 4);

    return 0;
}