#include <iostream>
using namespace std;

int main() {
  int start, end;
  cout << "Input starting integer: ";
  cin >> start;
  cout << "Input ending integer: ";
  cin >> end;

  if (end < start) {
    cout << "Invalid range" << endl;
  } else {
    cout << "Even numbers are: ";
    while (start <= end) {
      if (start % 2 == 0)
        cout << start << " ";
      start++;
    }
  }
  cout << endl;
  return 0;
}
