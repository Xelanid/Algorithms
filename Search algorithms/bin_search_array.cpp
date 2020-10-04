#include <bits/stdc++.h>

using namespace std;

long int bin_search(long int* a, long int l, long int r, long int x) {
    if (l == r - 1) {
        if (a[r] - x == x - a[l])
            return a[l];
        if (a[r] - x > x - a[l])
            return a[l];
        else
            return a[r];
    }
    long int m = (l + r) / 2;
    if (x == a[m])
        return a[m];
    if (x < a[m])
        return bin_search(a, l, m, x);
    else
        return bin_search(a, m, r, x);
}

int main() {
    long int n, k;
    cin >> n >> k;
    auto* arr = new long int[n];
    auto* req = new long int[k];

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    for (int i = 0; i < k; i++) {
        cin >> req[i];
        cout << bin_search(arr, 0, n - 1, req[i]) << "\n";
    }

    return 0;
}