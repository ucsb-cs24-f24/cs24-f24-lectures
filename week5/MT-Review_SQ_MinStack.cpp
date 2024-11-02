#include <iostream>
#include <stack>
using namespace std;

class MinStack {
  stack<int> primary;  // Primary stack to store all elements
  stack<int> minStack; // Stack to store the minimum elements

public:
  void push(int val) {
    primary.push(val); // Push value onto the primary stack
    // Push onto minStack if it's empty or the new value is <= current min
    if (minStack.empty() || val <= minStack.top()) {
      minStack.push(val);
    }
  }

  void pop() {
    if (primary.empty())
      return;                     // No operation if primary stack is empty
    int topValue = primary.top(); // Get the top value
    primary.pop();                // Pop from primary stack
    // If the top value is the same as the top of minStack, pop from minStack
    if (!minStack.empty() && topValue == minStack.top()) {
      minStack.pop();
    }
  }

  int top() {
    return primary.top(); // Return the top value of the primary stack
  }

  int getMin() {
    return minStack
        .top(); // Return the top value of the minStack (current minimum)
  }
};

int main() {
  MinStack minStack;

  minStack.push(-2);
  minStack.push(0);
  minStack.push(-3);

  cout << "Current minimum: " << minStack.getMin() << endl; // Returns -3

  minStack.pop();
  cout << "Top element after pop: " << minStack.top() << endl; // Returns 0
  cout << "Current minimum: " << minStack.getMin() << endl;    // Returns -2

  return 0;
}
