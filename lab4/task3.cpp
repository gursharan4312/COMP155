#include <iostream>
using namespace std;

class Box{
private:
  double length;
  double breadth;
  double height;

public:
  Box(double l=1,double b=1,double h=1){
    length=l;
    breadth=b;
    height=h;
  }
  void computeVolume(){
    double volume = length * breadth * height;
    cout<<"Volume of the box is: "<<volume<<endl;
  }
};

int main(){
  Box b1;
  Box b2(2);
  Box b3(2,3);
  Box b4(2,3,4);

  b1.computeVolume();
  b2.computeVolume();
  b3.computeVolume();
  b4.computeVolume();

  return 0;
}
