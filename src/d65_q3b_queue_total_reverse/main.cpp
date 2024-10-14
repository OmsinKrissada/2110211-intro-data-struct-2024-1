#include <iostream>

#include "queue.h"
#include "student.h"

int main() {
    CP::queue<int> q;
    int n;
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        int element;
        std::cin >> element;
        q.push(element);
    }
    q.reverse();
    // std::cout << q.front() << std::endl;
    // q.pop();
    // std::cout << q.front() << std::endl;
    // q.push(1);
    // q.push(2);
    // q.push(3);
    // q.push(4);
    // q.push(5);
    // // q.push(1);
    // // q.pop();
    // q.reverse();
    // q.pop();
    while (!q.empty()) {
        std::cout << q.front() << " ";
        q.pop();
    }
    std::cout << std::endl;
}