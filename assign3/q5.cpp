#include <iostream>
#include <stack>
#include <string>
using namespace std;

// precedence function
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

// check if character is operator
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int main() {
    string infix = "a+b-(d*f)+(c/e)";
    stack<char> s;
    string postfix = "";

    for (int i = 0; i < infix.length(); i++) {
        char c = infix[i];

        // If operand → add to output
        if (isalnum(c)) {
            postfix += c;
        }
        // If '(' → push
        else if (c == '(') {
            s.push(c);
        }
        // If ')' → pop until '('
        else if (c == ')') {
            while (!s.empty() && s.top() != '(') {
                postfix += s.top();
                s.pop();
            }
            if (!s.empty() && s.top() == '(')
                s.pop();
        }
        // If operator
        else if (isOperator(c)) {
            while (!s.empty() && precedence(s.top()) >= precedence(c)) {
                postfix += s.top();
                s.pop();
            }
            s.push(c);
        }
    }

    // Pop remaining operators
    while (!s.empty()) {
        postfix += s.top();
        s.pop();
    }

    cout << "Infix Expression: " << infix << endl;
    cout << "Postfix Expression: " << postfix << endl;

    return 0;
}