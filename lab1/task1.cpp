#include <iostream>
using namespace std;

int main() {

  int first, second, action;
  cout << "Enter First integer: ";
  cin >> first;
  cout << "Enter Second integer: ";
  cin >> second;

  cout << "Press 1 for addition" << endl;
  cout << "Press 2 for subtraction" << endl;
  cout << "Press 3 for multiplication" << endl;
  cout << "Press 4 for division" << endl;
  cout << "Press 5 for remainder" << endl;

  cin >> action;

  if (action == 1) {
    cout << first << " + " << second << " = " << first + second << endl;
  } else if (action == 2) {
    cout << first << " - " << second << " = " << first - second << endl;
  } else if (action == 3) {
    cout << first << " * " << second << " = " << first * second << endl;
  } else if (action == 4) {
    if (second == 0) {
      cout << "Cannot divide by zero." << endl;
    } else {
      cout << first << " / " << second << " = " << first / second << endl;
    }
  } else if (action == 5) {
    if (second == 0) {
      cout << "Cannot divide by zero." << endl;
    } else {
      cout << first << " % " << second << " = " << first % second << endl;
    }
  } else {
    cout << "Invalid selection try again" << endl;
  }

  return 0;
}
