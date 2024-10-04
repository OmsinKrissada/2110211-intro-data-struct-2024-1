#include <gmp.h>

#include <cmath>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

bool isPerfect(int n) {
    int sum = 0;
    for (int i = 1; i <= n / 2; i++) {
        if (n % i == 0) {
            sum += i;
        }
    }
    return sum == n;
}

set<double> primes;
bool isPrime(mpz_t n) {
    // if (primes.count(n)) return true;
    mpz_t i, i_square;
    mpz_init(i);
    mpz_add_ui(i, i, 2);
    mpz_pow_ui(i_square, i, 2);
    while (mpz_cmp(i_square, n) <= 0) {
        mpz_t mod_result;
        mpz_mod(mod_result, n, i);
        if (mpz_cmp(mod_result, 0)) return false;
        mpz_add_ui(i, i, 1);
        mpz_pow_ui(i_square, i, 2);
    }
    // primes.insert(n);
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int found = 0;
    mpz_t i;
    for (mpz_init(i); mpz_cmp_ui(i, 1000000); mpz_add_ui(i, i, 1)) {
        if (isPrime(i)) {
            cout << "testing p = " << i << endl;
            // double mer = pow(2, i) - 1;
            // if (isPrime(mer)) {
            found++;
            //     cout << "p = " << i << fixed << ", Mersenne prime: " << mer << ", Perfect number: " << mer * pow(2, i - 1) << endl;
            // }
        }
    }
}