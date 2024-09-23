#include<iostream>
using namespace std;

struct Point {
  int x;
  int y;
};

void getInputs(Point &points){
  cout << "Enter first point: ";
  cin >> points.x;

  cout << "Enter second point: ";
  cin >> points.y;
}

Point addPoints(Point a, Point b){
  Point c;
  c.x = a.x + b.x;
  c.y = a.y + b.y;
  return c;
}

int main(){

  Point first;
  Point second;
  getInputs(first);
  getInputs(second);

  Point sum = addPoints(first,second);

  cout << "Sum: " << sum.x << "," << sum.y<< endl;

  return 0;
}
