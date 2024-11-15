

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// vector<int> dailyTemperatures(vector<int> &temperatures)
// {
//     vector<int> result(temperatures.size(), 0);
//     for (int i = 0; i < temperatures.size(); i++)
//     { // n times
//         for (int j = i + 1; j < temperatures.size(); j++)
//         { // n - i - 1
//             if (temperatures[j] > temperatures[i])
//             {
//                 result[i] = j - i;
//                 break;
//             }
//         }
//     }
//     // Running time =  O(n^2)
//     // More careful analyis:
//     // T(n) = (n - 1 + n - 2 + n - 3 ...+ 3 + 2 + 1 ) * c
//     //      = (n-1)* n / 2 = n^2/2 - n/2
//     // T(n) = O(n^2) (worst case)
//     return result;
// }

vector<int> dailyTemperatures(vector<int> &temperatures)
{
    int n = temperatures.size();
    vector<int> answer(n, 0);
    stack<int> s;

    for (int i = 0; i < n; i++)
    {
        while (!s.empty() && temperatures[s.top()] < temperatures[i])
        {
            answer[s.top()] = i - s.top();
            s.pop();
        }
        s.push(i);
    }

    return answer;
}

int main()
{
    vector<int> vTemp = {73, 74, 75, 71, 69, 72, 76, 73};
    vector<int> dailyTemp = dailyTemperatures(vTemp);
    for (int d : dailyTemp)
        cout << d << " ";

    return 0;
}
