#include <iostream>
#include <vector>
using namespace std;

void reverse(vector<int> &v, vector<int>::iterator a, vector<int>::iterator b) {
    int temp;
    for (size_t i = 0; i < (b - a) / 2; i++) {
        temp = *(a + i);
        *(a + i) = *(b - 1 - i);
        *(b - 1 - i) = temp;
    }
}

int main() {
    // read input
    int n, a, b;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++) {
        int c;
        cin >> c;
        v.push_back(c);
    }
    cin >> a >> b;
    // call function
    reverse(v, v.begin() + a, v.begin() + b + 1);
    // display content of the vector
    for (auto &x : v) {
        cout << x << " ";
    }
    cout << endl;
}