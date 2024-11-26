#include <iostream>
using namespace std;

class FlightCrew {
protected:
    int crewID;
    int yearsOfService;
    int totalSalary;

public:
    FlightCrew(int crewID = 0, int yearsOfService = 0, int totalSalary = 0)
        : crewID(crewID), yearsOfService(yearsOfService), totalSalary(totalSalary) {}
};

class Pilot : public FlightCrew {
private:
    int flightHours;
    bool hasMilitaryExperience;

public:
    Pilot(int crewID = 0, int yearsOfService = 0, int totalSalary = 0, int flightHours = 0, bool hasMilitaryExperience = false)
        : FlightCrew(crewID, yearsOfService, totalSalary), flightHours(flightHours), hasMilitaryExperience(hasMilitaryExperience) {}

    double bonus() {
        return (flightHours * (totalSalary * 0.10));
    }

    bool isEligible() {
        return (yearsOfService >= 5 && flightHours > 100);
    }
};

class CabinCrew : public FlightCrew {
private:
    int trainingSessions;
    int totalFlightsServed;

public:
    CabinCrew(int crewID = 0, int yearsOfService = 0, int totalSalary = 0, int trainingSessions = 0, int totalFlightsServed = 0)
        : FlightCrew(crewID, yearsOfService, totalSalary), trainingSessions(trainingSessions), totalFlightsServed(totalFlightsServed) {}

    double bonus() {
        return (totalFlightsServed * (totalSalary * 0.05));
    }

    bool isEligible() {
        return (totalFlightsServed >= 10 && trainingSessions >= 5);
    }
};

int main() {
    Pilot pilot(101, 6, 50000, 120, true);
    cout << "Pilot Bonus: " << pilot.bonus() << endl;
    cout << "Pilot Promotion: " << (pilot.isEligible() ? "Eligible" : "Not Eligible") << endl;

    CabinCrew cabinCrew(201, 4, 30000, 6, 12);
    cout << "\nCabinCrew Bonus: " << cabinCrew.bonus() << endl;
    cout << "CabinCrew Promotion: " << (cabinCrew.isEligible() ? "Eligible" : "Not Eligible") << endl;

    return 0;
}

