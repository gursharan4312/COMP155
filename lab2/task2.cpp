#include<iostream>
using namespace std;

void calculateProduct(int &a, int &b, int &result){
  result = a*b;
}

void calculateDifference(int &a, int &b, int &result){
  result = a-b;
}

void calculateSum(int &a, int &b, int &result){
  result = a+b;
}

int main(){
  int a,b;
  cout << "Enter first int number: ";
  cin >> a;
  
  cout << "Enter second int number: ";
  cin >> b;

  int product,difference,sum;

  calculateProduct(a,b,product);
  calculateDifference(a,b,difference);
  calculateSum(a,b,sum);

  cout << "Product of " << a << " & " << b << " is " << product << endl; 
  cout << "Difference of " << a << " & " << b << " is " << difference<< endl; 
  cout << "Sum of " << a << " & " << b << " is " << sum << endl; 

  return 0;
}
