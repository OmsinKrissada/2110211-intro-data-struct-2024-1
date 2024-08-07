#include <iostream>
using namespace std;

int rows, cols;
int area_count;
int main() {
    cin >> rows >> cols;
    cin >> area_count;

    int m[rows][cols];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> m[i][j];
        }
    }

    for (int i = 0; i < area_count; i++) {
        int b1[2], b2[2];
        cin >> b1[0] >> b1[1] >> b2[0] >> b2[1];
        b1[0] -= 1;
        b1[1] -= 1;
        b2[0] -= 1;
        b2[1] -= 1;

        if (b1[0] > b2[0] || b1[1] > b2[1]) {
            cout << "INVALID\n";
            continue;
        }

        if (b1[0] >= rows || b1[1] >= cols || b2[0] < 0 || b2[1] < 0) {
            cout << "OUTSIDE\n";
            continue;
        }

        int max = m[b1[0]][b1[1]];
        for (int r = b1[0]; r <= b2[0] && r < rows; r++) {
            for (int c = b1[1]; c <= b2[1] && c < cols; c++) {
                int val = m[r][c];
                if (val > max) max = val;
            }
        }
        cout << max << endl;
    }
}