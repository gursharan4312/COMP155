#include <iostream>
#include <math.h>
using namespace std;

class Circle{
private:
  double radius;

public:
  Circle(double r=0){
    if(r<0){
      radius=0;
    }else{
      radius = r;
    }
  }
  double computeArea(){
    return M_PI * radius * radius;
  }
  double computeCircumference(){
    return 2 * M_PI * radius;
  }
};

int main(){
  double input;

  cout<<"Enter circle radius: ";
  cin >> input;
  Circle c1(input);

  cout<<"Circle Area: " << c1.computeArea() << endl;
  cout<<"Circle Circumference: " << c1.computeCircumference() << endl;

  return 0;
}
