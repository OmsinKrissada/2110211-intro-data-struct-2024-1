#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    short v;
    cin >> n >> k >> v;

    list<short> l;

    for (int i = 0; i < n; i++) {
        short c;
        cin >> c;
        l.push_back(c);
    }

    // shoot
    list<short>::iterator head = l.begin();
    for (int i = 0; i < k; i++) head++;
    head = l.insert(head, v);

    // eliminate(l, shoot);
    // eliminate
#ifdef DEBUG
    for (auto& e : l) cout << e << ' ';
    cout << endl;
#endif
    do {
        list<short>::iterator start = head, stop = head;
        int count = 1;
        short currentColor = *head;
#ifdef DEBUG
        cout << "Eliminating " << currentColor << endl;
#endif

        // left
        while (true) {
            auto nextStart = prev(start);
            if (*nextStart != currentColor) break;
            count++;
            start = nextStart;
            if (nextStart == l.begin()) break;
        }
        // right
        while (true) {
            auto nextStop = next(stop);
            if (nextStop == l.end()) break;
            if (*nextStop != currentColor) break;
            count++;
            stop = nextStop;
        }

#ifdef DEBUG
        cout << "Found " << count << " of them" << endl;
#endif

        if (count < 3) break;  // 2nd breaking condition, '2' and not '3' because we exclude self

        head = l.erase(start, next(stop));

        if (*head != *prev(head)) break;
#ifdef DEBUG
        for (auto& e : l) cout << e << ' ';
        cout << endl;
#endif
    } while (true);  // 1st breaking condition
    for (auto& e : l) cout << e << ' ';
    cout << endl;
}