#include <iostream>
using namespace std;

int main() {
    int n, k, p, q;
    cin >> n >> k >> p >> q;

    int rp = p, rq = q; // root of p, root of q

    while (rp != rq) {
        if (rp > rq) {
            rp = (rp - 1) / k;
            if (rp == 0) break;
        } else {
            rq = (rq - 1) / k;
            if (rq == 0) { rp = 0; break; }
        }
    }

    cout << rp;
}
