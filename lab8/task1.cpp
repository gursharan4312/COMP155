#include <iostream>
#include <string>
using namespace std;

class Vehicle {
protected:
    string modelName;

public:
    Vehicle(const string model) : modelName(model) {}

    virtual double calculatePerformance() const = 0;

    string getModelName() const {
        return modelName;
    }
};

class Car : public Vehicle {
private:
    double mileage;          
    double fuelTankCapacity;  
public:
    Car(const string model, double mileage, double fuelTankCapacity)
    : Vehicle(model), mileage(mileage), fuelTankCapacity(fuelTankCapacity) {}

    double calculatePerformance() const override {
        return mileage * fuelTankCapacity;  
    }
};

class Truck : public Vehicle {
private:
    double mileage;       
    double cargoWeight;   
public:
    Truck(const string model, double mileage, double cargoWeight)
    : Vehicle(model), mileage(mileage), cargoWeight(cargoWeight) {}

    double calculatePerformance() const override {
        return cargoWeight / mileage;   
    }
};

int main() {
    Car myCar("Toyota Camry", 30, 15);  
    Truck myTruck("Ford F-150", 15, 2000);  

    Vehicle* vehicles[] = { &myCar, &myTruck };

    for (Vehicle* v : vehicles) {
        std::cout << "Model: " << v->getModelName() << std::endl;
        std::cout << "Performance: " << v->calculatePerformance() << std::endl;
    }

    return 0;
}

