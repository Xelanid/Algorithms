#include <bits/stdc++.h>

using namespace std;

int split(int* a, int l, long int r){
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

void qsort(int* a, int l, long int r){
    if (l < r){
        int q = split(a, l, r);
        qsort(a, l, q);
        qsort(a, q + 1, r);
    }
}


int main() {
    long int n;
    cin >> n;
    int* arr = new int[n];

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    qsort(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
        cout << arr[i] << ' ';

    return 0;
}
/*
 #include <bits/stdc++.h>
#include <random>
#include <fstream>

using namespace std;

int split(vector<int> a, int l, long int r, int x){
    int i = l, j = r;

    while (i <= j) {
        while (a[i] < x) i++;
        while (a[j] > x) j--;
        if (i >= j) break;
        swap(a[i++], a[j--]);
    }
    return j;
}

int find(vector<int> a, int l, long int r, int k) {
    if (r - l == 1)
        return a[l];

    random_device random_device;
    mt19937 generator(random_device());
    uniform_int_distribution<> distribution(l, r - 1);
    int q = distribution(generator);
    int x = a[q];
/*
    cout << "array: ";
    for (int i = l; i < r; i++)
        cout << a[i] << ' ';
    cout << endl;
*/
/*
int m = split(a, l, r, x);
if (k < m - l + 1)
return find(a, l, m, k);
else
return find(a, m + 1, r, k - (m - l + 1));
}

int main() {
    int n;
    cin >> n;
    int* arr = new int[n];

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int m;
    vector<vector<int>> req, copy;
    cin >> m;
    int* ans = new int[m];
    req.resize(m);
    copy.resize(m);

    for (int i = 0; i < m; i++){
        copy[i].resize(n);
        for (int j = 0; j < n; j++)
            copy[i][j] = arr[j];
    }

    for (int i = 0; i < m; i++) {
        req[i].resize(3);
        for (int j = 0; j < 3; j++) {
            cin >> req[i][j];
            req[i][j] -= 1;
        }
    }
    for (int i = 0; i < m; i++) {
        ans[i] = find(copy[i], req[i][0], req[i][1], req[i][2]);
        cout << "answer: " << ans[i] << endl;
    }

    return 0;
}
 */