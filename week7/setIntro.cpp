#include <iostream>
#include <set>

using namespace std;

void printSet(set<int> &mySet) {
  // for(auto elm:mySet)
  //   cout << elm << " " ;

  // cout << endl;
  auto it = mySet.begin();
  // set<int>::iterator it = mySet.begin();
  while (it != mySet.end()) {
    cout << *it << " ";
    it++;
  }
  cout << endl;
}

int main() {
  set<int> s{30, 20, 25, 40, 35, 60};
  s.insert(30);
  printSet(s);

  auto it = s.find(35);
  cout << *it << endl;

  it = s.find(32);
  if (it != s.end())
    cout << *it << endl;

  it = s.find(30);
  
  cout << *++it << endl;

  s.erase(30);
  printSet(s);
  return 0;
}