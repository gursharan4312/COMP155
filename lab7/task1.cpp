#include <iostream>
using namespace std;

class Point{
  private:
    float x;
    float y;
  public:
    Point(float x = 0.0, float y = 0.0) : x(x), y(y) {}

    void display() const {
        cout << "Point(x: " << x << ", y: " << y << ")" << endl;
    }

    float getX() const {
        return x;
    }

    void setX(float value) {
        x = value;
    }

    float getY() const {
        return y;
    }

    void setY(float value) {
        y = value;
    }

    Point operator+(const Point &second) const {
        return Point(x + second.x, y + second.y);
    }
};

Point operator+(const Point &p, float scalar) {
    return Point(p.getX() + scalar, p.getY());
}

int main() {
    Point p1(3.2, 4.6);
    cout<<"p1: ";
    p1.display();

    Point p2(4.5, 7.1);
    cout<<"p2: ";
    p2.display();

    Point p3 = p1 + p2;
    cout << "p1 + p2: ";
    p3.display();

    Point p4 = p1 + 2.1;
    cout << "p1 + 2.1: ";
    p4.display();

    return 0;
}
