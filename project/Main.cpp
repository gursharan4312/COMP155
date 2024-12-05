#include <iostream>
#include <string>
#include <vector>
using namespace std;
#include "HeritageSite.cpp"
#include "Categoty.cpp"
#include "PreservationEffort.cpp"
#include "HeritageInventorySystem.cpp"

void displayMenu() {
    cout << "Main Menu:\n"
        << "1. Register a Heritage Site\n"
        << "2. View Heritage Sites\n"
        << "3. Add a Category\n"
        << "4. View Categories\n"
        << "5. Add Preservation Efforts\n"
        << "6. View Preservation History\n"
        << "7. Exit\n"
        << "Enter your choice: ";
}

int main() {
    HeritageInventorySystem system;
      
    // temp data
    system.addCategory(new Category("1","Category 1"));
    system.addCategory(new Category("2","Category 2"));

    system.addSite(new CulturalSite("1","Cultural Site","Vancouver","1","Cultural"));
    system.addSite(new NaturalSite("2","Natural Site","Richmond","2","Natural"));

    system.processPreservationEfforts("1", "Perserve Cultural site", "2024-12-04");
    system.processPreservationEfforts("2", "Perserve Natural site", "2024-11-03");

    string choice;
    while (true) {
        displayMenu();
        cin >> choice;
        if (choice == "1") {
            string id, name, loc, catID, type, extra;
            cout << "Enter Site ID: ";
            cin >> id;
            cout << "Enter Name: ";
            cin >> name;
            cout << "Enter Location: ";
            cin >> loc;
            cout << "Enter Category ID: ";
            cin >> catID;
            if(!system.hasCategory(catID)){
              cout << "\nCategory not found try again\n" << endl;
              continue;
            }
            cout << "Enter Site Type (Cultural/Natural): ";
            cin >> type;
            if (type == "Cultural" || type == "cultural") {
                cout << "Enter Cultural Significance: ";
                cin >> extra;
                system.addSite(new CulturalSite(id, name, loc, catID, extra));
            } else if (type == "Natural" || type == "natural") {
                cout << "Enter Ecosystem Type: ";
                cin >> extra;
                system.addSite(new NaturalSite(id, name, loc, catID, extra));
            } else {
                cout<<"\nWrong Site Type Try again\n"<<endl;
                continue;
            }
        } else if (choice == "2") {
            system.viewAllSites();
        } else if (choice == "3") {
            string id, name;
            cout << "Enter Category ID: ";
            cin >> id;
            cout << "Enter Category Name: ";
            cin >> name;
            system.addCategory(new Category(id, name));
        }else if(choice == "4"){
            system.viewAllCategories();
        } else if (choice == "5") {
            string id, desc, date;
            cout << "Enter Site ID: ";
            cin >> id;
            cout << "Enter Description: ";
            cin >> desc;
            cout << "Enter Date (YYYY-MM-DD): ";
            cin >> date;
            system.processPreservationEfforts(id, desc, date);
        } else if (choice == "6") {
            string id;
            cout << "Enter Site ID: ";
            cin >> id;
            system.viewPreservationHistory(id);
        } else if (choice == "7") {
            cout << "Exiting program.\n";
            break;
        } else {
            cout << "Invalid choice. Try again.\n";
        }
    }
    
    return 0;
}
