#ifndef __STUDENT_H__
#define __STUDENT_H__
#include <stack>
#include <vector>

using namespace std;

int eval_postfix(vector<pair<int, int> > v) {
    stack<int> s;
    for (auto &e : v) {
        if (e.first) {
            s.push(e.second);
        } else {
            int b = s.top();
            s.pop();
            int a = s.top();
            s.pop();
            if (e.second == 0) {
                s.push(a + b);
            } else if (e.second == 1) {
                s.push(a - b);
            } else if (e.second == 2) {
                s.push(a * b);
            } else if (e.second == 3) {
                s.push(a / b);
            }
        }
    }
    return s.top();
}

#endif
