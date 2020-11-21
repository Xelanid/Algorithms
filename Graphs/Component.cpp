#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<vector<int>> &u, int v, vector<int> &color, int cur) {
    color[v] = cur;

    for (int i = 0; i < u[v].size(); ++i)
        if (color[u[v][i]] == 0)
            dfs(u, u[v][i], color, cur);
}

int main() {
    int n, m, b, e;
    cin >> n >> m;

    vector<vector<int>> u(n);
    for (int i = 0; i < m; ++i) {
        cin >> b >> e;
        u[b - 1].push_back(e - 1);
        u[e - 1].push_back(b - 1);
    }

    vector<int> color(n, 0);
    int cur = 0;
    for (int i = 0; i < n; ++i)
        if (color[i] == 0)
            dfs(u, i, color, ++cur);

    cout << cur << "\n";
    for (int i = 0; i < n; ++i)
        cout << color[i] << " ";
    return 0;
}