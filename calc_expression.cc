#include <cassert>
#include <string>
#include <stack>
#include <iostream>

template<typename T>
typename T::value_type pop(T& stack) {
    typename T::value_type val = stack.top();
    stack.pop();
    return val;
}

int priority(int op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    assert(0);
}

int calc(char op, int x, int y) {
    switch(op) {
    case '+': 
        return x + y;
    case '-':
        return x - y;
    case '*':
        return x * y;
    case '/':
        return x / y;
    default:
        assert(0);
    }
}

int calc_expression(const std::string& expression) {
    std::stack<int> num_stack;
    std::stack<char> op_stack;

    std::string num_str;
    for (std::size_t i=0; i<expression.length(); ++i) {
        char c = expression[i];
        if (c >= '0' && c <= '9') {
            num_str.append(1, c);
            continue;
        }
        if (num_str.length() > 0) {
            num_stack.push(atoi(num_str.c_str()));
            num_str.clear();
        }
        if (op_stack.size() == 0 || priority(c) >= priority(op_stack.top())) {
            op_stack.push(expression[i]);
            continue;
        }
        while (op_stack.size() > 0) {
            if (priority(c) <= priority(op_stack.top())) {
                break;
            }
            int op = pop(op_stack);
            int y = pop(num_stack);
            int x = pop(num_stack);
            num_stack.push(calc(op, x, y));
        }
    }
    while (op_stack.size() > 0) {
        int op = pop(op_stack);
        int y = pop(num_stack);
        int x = pop(num_stack);
        num_stack.push(calc(op, x, y));
    }
    return num_stack.top();
}

int main() {
    std::cout << calc_expression("5*1+2+3*4+5-2/1") << std::endl;
    return 0;
}

