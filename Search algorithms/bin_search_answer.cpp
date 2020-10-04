#include <bits/stdc++.h>
#include <cmath>

using namespace std;

long long int sum(long long int m, int x, int y) {
    return m / x + m / y;
}

long long int bin_search(long long int n, int x, int y) {
    long long int l = -1, r = n * x;
    while (r - l > 1) {
        long long int m = (l + r) / 2;
        if (sum(m, x, y) < n - 1)
            l = m;
        else
            r = m;
    }

    return r;
}

int main() {
    long long int n;
    int x, y;
    cin >> n >> x >> y;
    cout << bin_search(n, x, y) + min(x, y);
    return 0;
}