#include<iostream>
#include <math.h>
using namespace std;

float calculateVolume(float r){
   return (4.0/3.0)*M_PI*r*r*r;
}

float calculateVolume(float r, float h){
   return (1.0/3.0)*M_PI*r*r*h;
}

float calculateVolume(float l, float w, float h){
   return l*w*h;

}

int main(){
  // sphere
  float sphereRadius = 2;
  float sphereVolume = calculateVolume(sphereRadius);
  
  // cone
  float coneRadius = 2;
  float coneHeight = 2;
  float coneVolume = calculateVolume(coneRadius, coneHeight);

  // cuboid
  float  length = 2;
  float width = 2;
  float height = 2;
  float  cuboidVolume = calculateVolume(length,width,height);

  cout << "sphere Volume : "<< sphereVolume <<endl<<"cone Volume : "<< coneVolume  <<endl<<"cuboid Volume : "<< cuboidVolume << endl;
  return 0;
}
