#include <iostream>

using std::cin, std::cout, std::endl;

int main() {
    int n, m;
    cin >> n >> m;

    int decode[n];
    int trackRecord[n] = {0};
    for (int i = 0; i != n; i++) {
        int wait;
        cin >> wait;
        decode[i] = wait;
    }

    bool op = true;
    int qs = 0;
    for (int t = 0; op; t++) {
        // cout << "current time : " << t << endl;
        // for (int i = 0; i != n; i++){
        //     cout << decode[i] << " : " << trackRecord[i] << endl;
        // } cout << endl;
        for (int i = 0; i != n && op; i++) {
            if (t == trackRecord[i]) {
                cout << t << "\n";
                trackRecord[i] += decode[i];
                qs++;
            }
            if (qs == m) {
                op = false;
                break;
            }
        }
    }
}
