#include <bits/stdc++.h>

using namespace std;

int split(long int* a, int l, long int r){
    int v = a[(l + r) / 2];
    int i = l, j = r;

    while (i <= j){
        while (a[i] < v) i++;
        while (a[j] > v) j--;
        if (i >= j) break;
        swap(a[i++], a[j--]);
    }
    return j;
}

void qsort(long int* a, int l, long int r){
    if (l < r){
        int q = split(a, l, r);
        qsort(a, l, q);
        qsort(a, q + 1, r);
    }
}

long int lower_bound(long int* a, long int x, long int n){
    long int l = -1, r = n;
    while (l < r - 1){
        long int m = (l + r) / 2;
        if (x <= a[m])
            r = m;
        else
            l = m;
    }
    return r;
}

int main() {
    long int n, k, l, r;
    cin >> n;
    long int* arr = new long int[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cin >> k;
    long int* ans = new long int[k];

    qsort(arr, 0, n - 1);
    for (int i = 0; i < k; i++) {
        cin >> l >> r;
        ans[i] = lower_bound(arr, r + 1, n) - lower_bound(arr, l, n);
        cout << ans[i] << " ";
    }

    return 0;
}