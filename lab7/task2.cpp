#include <iostream>
#include <cmath> 
using namespace std;

class Shape {
public:
    Shape() {}

    virtual double area() const {
        return 0.0; 
    }
};

class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    double area() const override {
        return M_PI * radius * radius;
    }
};

class Rectangle : public Shape {
private:
    double width, height;

public:
    Rectangle(double w, double h) : width(w), height(h) {}

    double area() const override {
        return width * height;
    }
};

class Triangle : public Shape {
private:
    double base, height;

public:
    Triangle(double b, double h) : base(b), height(h) {}

    double area() const override {
        return 0.5 * base * height;
    }
};

int main() {
    int choice;
    Shape* shape;

    cout << "Select a shape:"<<endl;
    cout << "1. Circle"<<endl;
    cout << "2. Rectangle"<<endl;
    cout << "3. Triangle"<<endl;
    cout << "Enter your choice: "<<endl;
    cin >> choice;

    if (choice == 1) {
        double radius;
        cout << "Enter the radius of the circle: ";
        cin >> radius;
        shape = new Circle(radius);
    } else if (choice == 2) {
        double width, height;
        cout << "Enter the width and height of the rectangle: ";
        cin >> width >> height;
        shape = new Rectangle(width, height);
    } else if (choice == 3) {
        double base, height;
        cout << "Enter the base and height of the triangle: ";
        cin >> base >> height;
        shape = new Triangle(base, height);
    } else {
        cout << "Invalid choice!"<<endl;
        return 1;
    }

    std::cout << "The area of the selected shape is: " << shape->area() << endl;

    return 0;
}

