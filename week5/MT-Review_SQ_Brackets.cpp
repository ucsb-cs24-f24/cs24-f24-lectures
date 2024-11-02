#include <iostream>
#include <stack>
using namespace std;

bool isValid(string s) {
    stack<char> k;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') {
            k.push(')');
        } else if (s[i] == '{') {
            k.push('}');
        } else if (s[i] == '[') {
            k.push(']');
        } else if (s[i] == ')' || s[i] == '}' || s[i] == ']') {
            if (k.empty() || k.top() != s[i]) {
                return false;
            }
            k.pop();
        }
    }

    return k.empty();
}

int main() {
    // Test cases
    string test1 = "()";
    string test2 = "()[]{}";
    string test3 = "(]";
    string test4 = "([)]";
    string test5 = "{[]}";

    // Validate test cases
    cout << "Test case 1: " << (isValid(test1) ? "Valid" : "Invalid") << endl;
    cout << "Test case 2: " << (isValid(test2) ? "Valid" : "Invalid") << endl;
    cout << "Test case 3: " << (isValid(test3) ? "Valid" : "Invalid") << endl;
    cout << "Test case 4: " << (isValid(test4) ? "Valid" : "Invalid") << endl;
    cout << "Test case 5: " << (isValid(test5) ? "Valid" : "Invalid") << endl;

    return 0;
}
