stack<int> sortUsingStack(stack<int>& s) {
    stack<int> temp_stack;

    while (!s.empty()) {
        int temp = s.top();
        s.pop();

        while (!temp_stack.empty() && temp_stack.top() < temp) {
            s.push(temp_stack.top());
            temp_stack.pop();
        }

        temp_stack.push(temp);
    }

    return temp_stack;
}
