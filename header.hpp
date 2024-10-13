// shamelessly yoinked from https://github.com/spad1e/competitive-programming/blob/master/library/header.hpp, for the 0.000000001 chance you're reading this, thanks

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ld> vld;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<pld> vpld;
typedef vector<vi> vvi;
typedef tuple<int, int, int> t3;
typedef tuple<int, int, int, int> t4;
typedef tuple<int, int, int, int, int> t5;
typedef tuple<ll, ll, ll> tll3;
typedef tuple<ll, ll, ll, ll> tll4;
typedef tuple<ll, ll, ll, ll, ll> tll5;

template <typename T>
using pq = priority_queue<T>;
template <typename T>
using pqr = priority_queue<T, vector<T>, greater<T>>;

#define rep0(a) for (int i = 0; i < a; ++i)
#define rep1(i, a) for (int i = 0; i < a; ++i)
#define rep2(i, a, b) for (int i = a; i <= b; ++i)
#define rep3(i, a, b, c) for (int i = a; i <= b; i += c)
#define rep(...) overload4(__VA_ARGS__, rep3, rep2, rep1, rep0)(__VA_ARGS__)
#define repd0(a) for (int i = a - 1; i >= 0; --i)
#define repd1(i, a) for (int i = a - 1; i >= 0; --i)
#define repd2(i, a, b) for (int i = b; i >= a; --i)
#define repd3(i, a, b, c) for (int i = b; i >= a; i -= c)
#define repd(...) overload4(__VA_ARGS__, repd3, repd2, repd1, repd0)(__VA_ARGS__)
#define trav(a, x) for (auto& a : x)

#define fullit(x) (x).begin(), (x).end()

#define sleep(ms) this_thread::sleep_for(chrono::milliseconds(ms));

class Timer {
    bool ended = false;
    string name;
    std::chrono::_V2::system_clock::time_point point;

   public:
    Timer(string name = "timer") : name(name) {
        point = chrono::high_resolution_clock::now();
    }

    void print(ostream& stream = cout) {
        auto duration = chrono::duration_cast<chrono::microseconds>(std::chrono::high_resolution_clock::now() - point).count();
        if (duration > pow(10, 6))
            stream << name << ": " << duration / pow(10, 6) << " s elapsed" << endl;
        else if (duration > pow(10, 3))
            stream << name << ": " << duration / pow(10, 3) << " ms elapsed" << endl;
        else
            stream << name << ": " << duration << " µs elapsed" << endl;
    }
};
