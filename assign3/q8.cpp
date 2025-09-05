#include <iostream>
#include <stack>
using namespace std;

class SpecialStack {
    stack<int> s; 
    stack<int> minStack; 

public:
    void push(int x) {
        s.push(x);
        
        // If the minStack is empty or the new element is smaller than 
        // the top of minStack, push it onto minStack
        if (minStack.empty() || x <= minStack.top()) {
            minStack.push(x);
        } else {
            
            // Otherwise, push the top element of minStack 
            // again to keep the minimum unchanged
            minStack.push(minStack.top());
        }
    }

    // Pop the top element from the stack
    int pop() {
        if (s.empty()) {
            return -1;
        }
        // Pop from both stacks
        int poppedElement = s.top();
        s.pop();
        minStack.pop();
        return poppedElement;
    }

    // Return the top element of the stack without removing it
    int peek() {
        if (s.empty()) {
            return -1;
        }
        return s.top();
    }

    // Check if the stack is empty
    bool isEmpty() {
        return s.empty();
    }

    // Get the minimum element in the stack
    int getMin() {
        if (minStack.empty()) {
            return -1;
        }
        return minStack.top();
    }
};

int main() {
    SpecialStack stack;
    
    stack.push(18);
    stack.push(19);
    stack.push(29);
    stack.push(15);
    stack.push(16);

    cout << stack.getMin() << endl;

    return 0;
}