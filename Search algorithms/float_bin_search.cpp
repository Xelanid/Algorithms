#include <bits/stdc++.h>

using namespace std;

long double f(long double x) {
    return x * x + sqrt(x);
}

long double bin_search(long double c) {
    long double l = 0, r = 1, m;
    while (f(r) < c)
        r *= 2;
    for (int i = 0; i < 60; i++) {
        m = (l + r) / 2;
        if (f(m) < c)
            l = m;
        else
            r = m;
    }
    return r;
}

int main() {
    long double c;
    cin >> c;
    cout.precision(7);
    cout << bin_search(c);
    return 0;
}