#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Employee {
protected:
    string employeeID;
    string name;
    double salary;

public:
    Employee(string id, string n, double sal)
        : employeeID(id), name(n), salary(sal) {}

    virtual double calculateBonus() const = 0;
    virtual bool isEligibleForPromotion() const = 0; 

    double getSalary() const { return salary; }

    friend void displayEmployeeDetails(const Employee& emp);
};

class Manager : public Employee {
private:
    int numberOfTeams;

public:
    Manager(string id, string n, double sal, int teams)
        : Employee(id, n, sal), numberOfTeams(teams) {}

    double calculateBonus() const override {  
        return 0.1 * salary * numberOfTeams;
    }

    bool isEligibleForPromotion() const override {  
        double totalSalary = calculateBonus() + salary;
        return totalSalary >= 70000;
    }
};

class Engineer : public Employee {
private:
    int yearsOfExperience;

public:
    Engineer(string id, string n, double sal, int years)
        : Employee(id, n, sal), yearsOfExperience(years) {}

    double calculateBonus() const override {  
        return yearsOfExperience * 1000;
    }

    bool isEligibleForPromotion() const override {
    return yearsOfExperience >= 5;
    }
};

void displayEmployeeDetails(const Employee& emp) {
    cout << "Employee ID: " << emp.employeeID << endl;
    cout << "Name: " << emp.name << endl;
    cout << "Salary: $" << emp.salary << endl;
    cout << "Bonus: $" << emp.calculateBonus() << endl;
    cout << "Eligible for Promotion: " 
         << (emp.isEligibleForPromotion() ? "Yes" : "No") << endl;
}

class Department {
private:
    string departmentName;
    vector<Employee*> employees;

public:
    Department(string name) : departmentName(name) {}

    void addEmployee(Employee* emp) {
        employees.push_back(emp);
    }

    void displayDepartmentDetails() const {
        cout << "Department: " << departmentName << endl;
        for (const Employee* emp : employees) {
            displayEmployeeDetails(*emp);  
            cout << endl;
        }
    }
};

int main() {
    Department devDepartment("Development");

    Manager manager1("M001", "John", 85000, 4);
    Manager manager2("M002", "Dany", 50000, 2);
    Engineer engineer1("E001", "Bob", 60000, 6);
    Engineer engineer2("E002", "Charlie", 55000, 3);

    devDepartment.addEmployee(&manager1);
    devDepartment.addEmployee(&manager2);
    devDepartment.addEmployee(&engineer1);
    devDepartment.addEmployee(&engineer2);

    devDepartment.displayDepartmentDetails();

    return 0;
}
