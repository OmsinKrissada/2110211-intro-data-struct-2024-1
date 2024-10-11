#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "stack.h"

template <typename T>
void migrate(std::stack<T>& from, std::stack<T>& to) {
    std::stack<T> tmp;
    for (size_t i = 0; i < from.size() / 2; i++) {
        tmp.push(from.top());
        from.pop();
    }
    while (!from.empty()) {
        to.push(from.top());
        from.pop();
    }
    while (!tmp.empty()) {
        from.push(tmp.top());
        tmp.pop();
    }
}

template <typename T>
void CP::stack<T>::pop() {
    // modify method here
    if (stack_a.empty()) {
        migrate(stack_b, stack_a);
    }
    stack_a.pop();
}

template <typename T>
const T& CP::stack<T>::top() {
    // modify method here
    if (stack_a.empty()) {
        migrate(stack_b, stack_a);
    }
    return stack_a.top();
}

template <typename T>
const T& CP::stack<T>::bottom() {
    // write your code here
    if (stack_b.empty()) {
        migrate(stack_a, stack_b);
    }
    return stack_b.top();
}

template <typename T>
void CP::stack<T>::push_bottom(const T& element) {
    // write your code here
    stack_b.push(element);
}

template <typename T>
void CP::stack<T>::pop_bottom() {
    // write your code here
    if (stack_b.empty()) {
        migrate(stack_a, stack_b);
    }
    stack_b.pop();
}
#endif