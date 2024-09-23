#include<iostream>
using namespace std;

struct Point {
  int x;
  int y;
};

struct Rectangle {
  Point top_left;
  Point bottom_right;
};

int calculateArea(Rectangle rec){
  int length1 = rec.bottom_right.x - rec.top_left.x;
  int length2 = rec.top_left.y - rec.bottom_right.y;
  return abs(length1) * abs(length2);
}

int main(){
  Point a = {1,7};
  Point b = {7,2};
  
  Rectangle rec = {a,b};

  cout << "Area of Rectangle with top left as (1,7) and bottom right as (7,2) is "<< calculateArea(rec) <<endl;

  return 0;
}
