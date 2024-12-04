#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &v, vector<int> &left, vector<int> &right)
{
  int i = 0, j = 0, k = 0;
  while (i < left.size() && j < right.size())
  {
    if (left[i] < right[j])
    {
      v[k] = left[i];
      i++;
      k++;
    }
    else
    {
      v[k] = right[j];
      j++;
      k++;
    }
  }

  while (i < left.size())
  {
    v[k] = left[i];
    i++;
    k++;
  }

  while (j < right.size())
  {
    v[k] = right[j];
    k++;
    j++;
  }
}

void mergeSort(vector<int> &v)
{
  if (v.size() <= 1)
    return;
  int mid = (v.size() - 1) / 2;
  vector<int> left(v.begin(), v.begin() + mid + 1);
  vector<int> right(v.begin() + mid + 1, v.end());
  mergeSort(left);
  mergeSort(right);
  merge(v, left, right);
}

int main()
{
  vector<int> v1 = {9, 8, 7, 6, 5, 4, 3, 2, 1};
  vector<int> v2 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  vector<int> v3 = {1, 9, 2, 8, 3, 7, 4, 6, 5};
  vector<int> v4 = {5, 4, 6, 3, 7, 2, 8, 1, 9};
  mergeSort(v4);
  for (int i = 0; i < v4.size(); i++)
  {
    cout << v4[i] << " ";
  }
  cout << endl;
}