#include <iostream>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    long long size = 0, cap = 1;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        char op;
        int times;
        cin >> op >> times;
        switch (op) {
            case 'p':
                size += times;
                while (cap < size) {
                    cap = cap << 1;
                }
                break;
            case 'o':
                size -= times;
                break;
            case 'r':
                if (times > cap) cap = times;
                size = times;
                break;
        }
    }

    cout << cap - size;
}
