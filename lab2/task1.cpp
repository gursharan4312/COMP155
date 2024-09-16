#include<iostream>
using namespace std;

float min(float, float, float);

int main(){
  float a,b,c;
  cout << "Enter first float number: ";
  cin >> a;
  
  cout << "Enter second float number: ";
  cin >> b;
  
  cout << "Enter third float number: ";
  cin >> c;

  cout <<  "Minium of " << a << ", " << b << " & " << c << " is " << min(a,b,c) << endl;
  return 0;
}

float min(float first, float second, float third){
  if(first <= second && first <= third){
    return first;
  }else if(second <= first && second <= second){
    return second;
  }else{
    return third;
  }
}
