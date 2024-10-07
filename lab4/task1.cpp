#include <iostream>
using namespace std;

class Point{
private:
  int x;
  int y;
  
public:
  Point(){
    x=0;
    y=0;
  }
  int getX(){
    return x;
  }
  int getY(){
    return y;
  }
  void setX(int x_value){
    x=x_value;
  }
  void setY(int y_value){
    y=y_value;
  }
  void display(){
    cout<<"Point coordinates: "<<x<<","<<y<<endl;
  }
};

int main(){
  Point p1;
  Point p2;
  p1.display();
  p2.display();
  
  int input;

  cout<<"Enter x for p1: ";
  cin >> input;
  p1.setX(input);
  cout<<"Enter y for p1: ";
  cin >> input;
  p1.setY(input);

  cout<<"Enter x for p2: ";
  cin >> input;
  p2.setX(input);
  cout<<"Enter y for p2: ";
  cin >> input;
  p2.setY(input);

  cout << "Sum for p1: "<< p1.getX() + p1.getY() << endl;
  cout << "Sum for p2: "<< p2.getX() + p2.getY() << endl;

  return 0;
}
