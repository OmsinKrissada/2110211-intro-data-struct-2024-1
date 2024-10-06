#ifndef __STUDENT_H__
#define __STUDENT_H__

template <typename T>
void CP::stack<T>::moveInsert(int k, CP::stack<T> &s2, int m) {
    // your code here
    if (m > s2.size()) m = s2.size();
    CP::stack<T> insert_buffer;
    for (int i = 0; i < m; i++) {
        insert_buffer.push(s2.top());
        s2.pop();
    }

    CP::stack<T> move_buffer;
    for (int i = 0; i < k; i++) {
        move_buffer.push(top());
        pop();
    }

    while (!insert_buffer.empty()) {
        push(insert_buffer.top());
        insert_buffer.pop();
    }

    while (!move_buffer.empty()) {
        push(move_buffer.top());
        move_buffer.pop();
    }
}
#endif
