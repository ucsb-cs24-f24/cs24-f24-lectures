#include <iostream>
using namespace std;

class Student {
  public:
    string name;
    int age;
    int *ptr;

  Student(string n, int a, int *p) {
    name = n;
    age = a;
    ptr = p;
  }
  void display() {
    cout << name << endl;
    cout << age << endl;
    cout << *ptr << endl;
  }

  Student &operator=(const Student &other) {
    name = other.name;
    age = other.age;
    
    *ptr = *(other.ptr);
    return *this;
  }
};

int main() {
  int a = 4;
  int b = 8;

  Student s1("Alice", 20, &a);
  Student s2("Bob", 21, &b);
  s1.display();
  s2.display();

  s1 = s2;
  s2.name = "Tara";
  *(s2.ptr) = 9;

  s1.display();
  s2.display();

  return 0;
}