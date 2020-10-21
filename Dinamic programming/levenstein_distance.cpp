#include <iostream>
#include <string>
#include <vector>

using namespace std;

int mini (int a, int b, int c) {
    return min(min(a, b), c);
}

void distance(string s1, string s2) {
    int n = s1.length(), m = s2.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 0; i <= n; ++i)
        for (int  j = 0; j <= m; ++j)
            if (i == 0)
                dp[i][j] = j;
            else if (j == 0)
                dp[i][j] = i;
            else if (s1[i - 1] == s2[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = mini(dp[i -1][j -1], dp[i - 1][j], dp[i][j - 1]) + 1;

    cout << dp[n][m];
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    distance(s1, s2);
    return 0;
}