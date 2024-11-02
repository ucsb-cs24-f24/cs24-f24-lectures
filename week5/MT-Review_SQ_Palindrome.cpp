#include <iostream>
#include <stack>
#include <queue>

using namespace std;

void make_palindrome(queue<int>& q) {
    queue<int> tempQueue;
    stack<int> tempStack;

    // Copy elements from q to tempQueue and tempStack
    while (!q.empty()) {
        tempQueue.push(q.front());
        tempStack.push(q.front());
        q.pop();
    }

    // Restore the original queue from tempQueue
    while (!tempQueue.empty()) {
        q.push(tempQueue.front());
        tempQueue.pop();
    }

    // Append the elements from tempStack to q to form a palindrome
    while (!tempStack.empty()) {
        q.push(tempStack.top());
        tempStack.pop();
    }
}

void popAndPrint(const queue<int>& q) {
    queue<int> temp = q; // Make a copy of the queue to print it
    while (!temp.empty()) {
        cout << temp.front() << " ";
        temp.pop();
    }
    cout << endl;
}

int main() {
    queue<int> q;

    // Add elements to the queue
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    cout << "Original queue: ";
      popAndPrint(q);

    // Convert to palindrome
    make_palindrome(q);

    cout << "Palindrome queue: ";
      popAndPrint(q);

    return 0;
}
