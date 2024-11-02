#include <vector>
#include <stack>
#include <iostream>
using namespace std;

vector<vector<int>> stockWaitDays(const vector<vector<int>>& prices) {
    int n = prices.size();
    int m = n > 0 ? prices[0].size() : 0;
    vector<vector<int>> answer(n, vector<int>(m, 0));

    for (int i = 0; i < n; ++i) {
        stack<int> stk;
        for (int j = 0; j < m; ++j) {
            while (!stk.empty() && prices[i][stk.top()] < prices[i][j]) {
                int prev_day = stk.top();
                stk.pop();
                answer[i][prev_day] = j - prev_day;
            }
            stk.push(j);
        }
    }

    return answer;
}

int main() {
    // Example usage
    vector<vector<int>> prices = {
        {5, 3, 6, 7, 4},
        {8, 4, 6, 3, 5}
    };

    vector<vector<int>> result = stockWaitDays(prices);

    // Print the result
    for (const auto& row : result) {
        for (int days : row) {
            cout << days << " ";
        }
        cout << endl;
    }

    return 0;
}


// The time complexity of the solution is O(n * m), where n is the number of stocks and m is the number of days. This is because each stock's prices are processed in O(m) time, and this is repeated for n stocks. The space complexity is also O(n * m) due to the answer matrix, with an additional O(m) space for the stack used during processing. 
