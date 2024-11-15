#include <iostream>
#include <map>

using namespace std;

void printMap(map<int, int> &myMap)
{
  auto it = myMap.begin();
  while (it != myMap.end())
  {
    cout << it->first << "-" << it->second << " ";
    it++;
  }
  cout << endl;
}

map<int, int> merge(map<int, int> &itm1, map<int, int> &itm2)
{
  map<int, int> result;
  // map<int, int>::iterator it = itm1.begin();
  auto it = itm1.begin();
  while (it != itm1.end())
  {
    result.insert(*it);
    it++;
  }

  it = itm2.begin();
  while (it != itm2.end())
  {
    if (itm1.find(it->first) == itm1.end())
    {
      result.insert(*it);
    }
    else
    {
      result[it->first] += it->second;
    }
    it++;
  }

  return result;
}

int main()
{
  map<int, int> items1 = {{1, 1}, {4, 5}, {3, 8}};
  map<int, int> items2 = {{3, 1}, {1, 5}, {6, 6}};
  auto answer = merge(items1, items2);

  printMap(answer);

  return 0;
}