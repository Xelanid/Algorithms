#include <bits/stdc++.h>

using namespace std;

int* merge(int* l, int* r, long int len_l, long int len_r) {
    long int q = len_l, w = len_r;
    long int i = 0, j = 0;
    int* c = new int[len_l + len_r];

    while (i + j < q + w){
        if ((j == w) || ((i < q) && (l[i] < r[j]))){
            c[i + j] = l[i];
            i++;
        }
        else{
            c[i + j] = r[j];
            j++;
        }
    }
    return c;
}

int* merge_sort(int* a, long int len) {
    if (len == 1) return a;

    long int len_l = len / 2, len_r = len - len_l;

    int* l = new int[len_l];
    int* r = new int[len_r];

    for (int i = 0; i < len_l; i++)
        l[i] = a[i];
    for (int i = len_l; i < len; i++)
        r[i - len_l] = a[i];

    l = merge_sort(l, len_l);
    r = merge_sort(r, len_r);
    return merge(l, r, len_l, len_r);
}

int main() {
    long int n;
    cin >> n;
    int* arr = new int[n];

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    arr = merge_sort(arr, n);

    for (int i = 0; i < n; i++)
        cout << arr[i] << ' ';

    return 0;
}