#include <iostream>
#include <vector>
#include <stack>

using namespace  std;

bool dfs(int v, vector<int> &used, vector<vector<int>> &a, stack<int> &sort) {
    used[v] = 1;
    for (int i = 0; i < a[v].size(); ++i) {
        int v_cur = a[v][i];
        if (used[v_cur] == 0) {
            if (dfs(v_cur, used, a, sort))
                return true;
        }
        else if (used[v_cur] == 1)
            return true;

    }
    used[v] = 2;
    sort.push(v);
    return false;
}

bool top_sort(vector<vector<int>> &u, stack<int> &sort) {
    vector<int> used(u.size(), 0);

    for (int i = 0; i < u.size(); ++i)
        if (!used[i])
            if (dfs(i, used, u, sort))
                return true;
    return false;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);

    int x, y;
    for (int i = 0; i < m; ++i) {
        cin >> x >> y;
        g[x - 1].push_back(y - 1);
    }

    stack<int> sort;
    if (top_sort(g, sort)) {
        cout << -1;
        return 0;
    }

    for (int i = 0; i < n; ++i) {
        cout << sort.top() + 1 << " ";
        sort.pop();
    }
    return 0;
}