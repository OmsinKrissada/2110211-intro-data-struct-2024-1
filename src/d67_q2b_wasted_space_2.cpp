#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    size_t size = 0, cap = 1;
    size_t n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        char op;
        int times;
        cin >> op >> times;
        switch (op) {
            case 'p':
                size += times;
                while (cap < size) {
                    cap *= 2;
                }
                break;
            case 'o':
                size -= times;
                if (size < 0) size = 0;
                break;
            case 'r':
                if (times > cap) {
                    cap = times;
                }
                size = times;
                break;
        }
    }

    cout << cap - size;
}
