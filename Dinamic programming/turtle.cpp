#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

void search_way(vector<vector<int>>& dp, vector<vector<int>>& arr, int n, int m) {
    int i = n - 1, j = m - 1;
    string str;
    while ((i > 0) && (j > 0)) {
        if (dp[i][j] - arr[i][j] == dp[i - 1][j]) {
            str += "D";
            i--;
        }
        else {
            str += "R";
            j--;
        }
    }

    if (i == 0)
        while (j > 0) {
            str += "R";
            j--;
        }

    if (j == 0)
        while (i > 0) {
            str += "D";
            i--;
        }

    reverse(str.begin(), str.end());
    cout << str;
}

void gold_fever(vector<vector<int>>& arr, int n, int m) {
    vector<vector<int>> dp(n, vector<int>(m, 0));
    dp = arr;

    dp[0][0] = arr[0][0];
    for (int i = 1; i < n; ++i)
        dp[i][0] = dp[i - 1][0] + arr[i][0];
    for (int i = 1; i < m; ++i)
        dp[0][i] = dp[0][i - 1] + arr[0][i];
    for (int i = 1; i < n; ++i)
        for (int j = 1; j < m; ++j)
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + arr[i][j];

    cout << dp[n - 1][m - 1] << "\n";
    search_way(dp, arr, n, m);
}

void commands(int n, int m) {
    vector<vector<int>> arr(n);

    for (int i = 0; i < n; ++i) {
        arr[i].resize(m);
        for (int j = 0; j < m; ++j)
            cin >> arr[i][j];
    }

    gold_fever(arr, n, m);
}

int main() {
    int n, m;
    cin >> n >> m;
    commands(n, m);
    return 0;
}