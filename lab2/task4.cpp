#include<iostream>
using namespace std;

float calculateDeliveryCharges(float w,float d,float r = 0.5, float i = 5,bool p=false){
  float charges = (w * d * r) + i;

  if(p){
    return charges * 1.1;
  }
  return charges;
}

int main(){
  float weight = 10;
  float distance = 2;
  cout << calculateDeliveryCharges(weight,distance) << endl;
  cout << calculateDeliveryCharges(weight,distance, 1) << endl;
  cout << calculateDeliveryCharges(weight,distance, 1,10) << endl;
  cout << calculateDeliveryCharges(weight,distance, 1,10, true) << endl;
  return 0;
}
