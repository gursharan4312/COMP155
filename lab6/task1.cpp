#include <iostream>

using namespace std;

class Person {
protected:
    string firstName;
    string lastName;

public:
  Person(string fN = "Unknown", string lN= "Unknown"){
    firstName = fN;
    lastName = lN;
  }

  void getFullName(){
    cout << "Full Name: " << firstName << " " << lastName << endl;
  }
};

class Employee {
protected:
    int employeeID;
    string department;

public:
    Employee(int eID = 0, string depart= "None") {
    employeeID = eID;
    department = depart;
  }

    void getEmployeeDetails(){
        cout << "Employee ID: " << employeeID << endl;
        cout << "Department: " << department << endl;
    }
};

class Manager : public Person, public Employee {
private:
    int teamSize;

public:
    Manager(string firstName = "Unknown", string lastName = "Unknown",
            int employeeID = 0, string department = "None", int teamSize = 0)
        : Person(firstName, lastName), Employee(employeeID, department), teamSize(teamSize) {}

    void getManagerDetails(){
        getFullName();
        getEmployeeDetails();
        cout << "Team Size: " << teamSize << endl;
    }
};

int main() {
    Person person("John", "Doe");
    cout << "Person Details:" << endl;
    person.getFullName();

    Employee employee(123, "HR");
    cout << "\nEmployee Details:" << endl;
    employee.getEmployeeDetails();

    Manager manager("Alice", "Johnson", 456, "Sales", 10);
    cout << "\nManager Details:" << endl;
    manager.getManagerDetails();

    return 0;
}

