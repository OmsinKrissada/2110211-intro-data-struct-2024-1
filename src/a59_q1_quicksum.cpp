#include <iostream>
#include <vector>
using namespace std;

int rows, cols, k;

int main() {
    cin >> rows >> cols >> k;

    int p[rows][cols];
    cin >> p[0][0];
    for (int j = 1; j < cols; j++) {
        int current;
        cin >> current;
        p[0][j] = p[0][j - 1] + current;
    }
    for (int i = 1; i < rows; i++) {
        int current;
        cin >> current;
        p[i][0] = p[i - 1][0] + current;
        for (int j = 1; j < cols; j++) {
            cin >> current;
            p[i][j] = p[i - 1][j] + p[i][j - 1] - p[i - 1][j - 1] + current;
        }
    }

    for (int i = 0; i < k; i++) {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        int result = p[r2][c2];
        if (r1 > 0 && c1 > 0) {
            result += p[r1 - 1][c1 - 1];
        }
        if (r1 > 0) {
            result -= p[r1 - 1][c2];
        }
        if (c1 > 0) {
            result -= p[r2][c1 - 1];
        }
        cout << result << endl;
    }
}

/* earlier & simpler version (4 KB more mem usage + 0.003s longer execution time lolll) */

/*
#include <iostream>
#include <vector>
using namespace std;

int rows, cols, k;

int gp(int* prefixes, int i, int j) {
    if (i < 0 || j < 0)
        return 0;
    else
        return *(prefixes + i * cols + j);
}

int main() {
    cin >> rows >> cols >> k;

    int p[rows][cols];
    cin >> p[0][0];
    for (int j = 1; j < cols; j++) {
        int current;
        cin >> current;
        p[0][j] = p[0][j - 1] + current;
    }
    for (int i = 1; i < rows; i++) {
        int current;
        cin >> current;
        p[i][0] = p[i - 1][0] + current;
        for (int j = 1; j < cols; j++) {
            cin >> current;
            p[i][j] = p[i - 1][j] + p[i][j - 1] - p[i - 1][j - 1] + current;
        }
    }

    for (int i = 0; i < k; i++) {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        cout << gp(&p[0][0], r2, c2) - gp(&p[0][0], r2, c1 - 1) - gp(&p[0][0], r1 - 1, c2) + gp(&p[0][0], r1 - 1, c1 - 1) << endl;
    }
}
*/