#include <iostream>
#include <vector>

using namespace std;

void num_visits(const int* par, int n) {
    vector<int> out;
    int i = n - 1;
    out.push_back(i);
    do {
        i = par[i];
        out.push_back(i);
    } while(i > 0);

    cout << out.size() - 1 << "\n";
    for (auto i = out.rbegin(); i != out.rend(); ++i)
        cout << *i + 1 << " ";

}

void gold_fever(const int* arr, int* dp, int n, int k) {
    int* par = new int [n];
    par[0] = 0;
    for (int i = 1; i < n; ++i) {
        int rich_i = i - 1;
        for (int j = max(0, i - k); j <= i - 1; ++j)
            if (dp[j] > dp[rich_i])
                rich_i = j;
        dp[i] = dp[rich_i] + arr[i];
        par[i] = rich_i;
    }
    cout << dp[n - 1] << "\n";
    num_visits(par, n);
}

void commands() {
    int n, k, sum = 0, cnt = 0;
    cin >> n >> k;
    int* dp = new int [n];
    int* arr = new int [n];

    arr[0] = 0;
    arr[n - 1] = 0;
    dp[0] = 0;
    for (int i = 1; i < n - 1; ++i)
        cin >> arr[i];

    gold_fever(arr, dp, n, k);
}

int main() {
    commands();
    return 0;
}