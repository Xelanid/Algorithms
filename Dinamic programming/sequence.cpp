#include <iostream>
#include <vector>

using namespace std;

void max_seq(int* arr, int n) {
    int* dp = new int[n];
    int* par = new int[n];
    dp[0] = 1;
    par[0] = -1;

    for (int i = 1; i < n; ++i) {
        int max = 0;
        par[i] = -1;
        for (int j = i - 1; j >= 0; --j)
            if ((arr[i] > arr[j]) && (dp[j] > max)) {
                max = dp[j];
                par[i] = j;
            }
        dp[i] = max + 1;
    }

    int max = dp[0], last = 0;
    for (int i = 0; i < n; ++i)
        if (dp[i] > max) {
            max = dp[i];
            last = i;
        }

    vector<int> seq(0);
    seq.push_back(arr[last]);
    while (par[last] != -1) {
        seq.push_back(arr[par[last]]);
        last = par[last];
    }
    cout << max << "\n";
    for (auto i = seq.rbegin(); i != seq.rend(); ++i)
        cout << *i << " ";
}

void commands() {
    int n;
    cin >> n;
    int* arr = new int[n];
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    max_seq(arr, n);
};

int main() {
    commands();
    return 0;
}