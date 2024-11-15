#include <iostream>
#include <map>
#include <set>

using namespace std;

void printMap(set<int> &myMap) {}

int main() {
  set<pair<string, int>> grocery_list;
  map<string, int> groceries;
  groceries["Banana"] = 2;
  groceries["Apple"] = 1;
  groceries["Milk"] = 3;
  groceries["Bead"] = 5;

  for (auto elm : groceries)
    cout << elm.first << " ";

  cout << endl;

  return 0;
}