#include <iostream>
using namespace std;

template <typename T>
class MyClass {
private:
  T secret;  

public:
  MyClass(T value) : secret(value) {}

  void display() const {
    cout << "Secret value: " << secret << endl;
  }

  void setSecret(T value) {
    secret = value;
  }

  T getSecret() const {
    return secret;
  }
};

template <typename T>
class MyFriendClass {
public:
  void change(MyClass<T>& obj, T value) {
    obj.setSecret(value);      
  }
};

int main() {
  MyClass<int> myIntObj(2);
  myIntObj.display();

  MyFriendClass<int> myIntFriend;
  myIntFriend.change(myIntObj, 10);
  myIntObj.display();

  MyClass<float> myFloatObj(3.14);
  myFloatObj.display();

  MyFriendClass<float> myFloatFriend;
  myFloatFriend.change(myFloatObj, 6.28);
  myFloatObj.display();

  return 0;
}

