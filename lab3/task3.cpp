#include<iostream>
using namespace std;

struct Student {
  int studentID;
  string name;
  float cgpa;
};

int main(){

  Student students[3] = {{1,"Alice",3.7},{2,"Bob",3.1},{3,"Charlie",3.5}};

  for(Student student: students){
    cout << "StudentId: " << student.studentID << ", Name: " << student.name << ", cgpa: " << student.cgpa << endl;
  }

  return 0;
}
