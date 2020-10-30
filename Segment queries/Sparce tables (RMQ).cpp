#include <iostream>
#include <cmath>

using namespace std;

typedef long long ll;
const ll len = 1e5;
const ll wid = 20;

ll a[len], req[len][wid];

void fill_a(ll a_1, ll n) {
    a[0] = a_1;
    for (ll i = 1; i < n; ++i)
        a[i] = (23 * a[i - 1] + 21563) % 16714589;
}

void fill_req(ll n) {
    ll k_max = 1, t = 2;
    while (t < n) {
        t = t << 1;
        k_max++;
    }

    for (ll i = 0; i < n; ++i)
        req[i][0] = a[i];
    for (ll i = 1; i < k_max; ++i) {
        ll k2 = 1 << (i - 1);
        for (ll j = 0; j < n; ++j) {
            ll m2 = len;
            if (j + k2 < n)
                m2 = req[j + k2][i - 1];
            req[j][i] = min(req[j][i - 1], m2);
        }
    }
}

ll rmq(ll u, ll v) {
    if (u > v)
        swap(u, v);
    ll k = 1, k2 = 2;
    while (k2 < v - u + 1) {
        k++;
        k2 = k2 << 1;
    }
    k--;
    k2 = k2 >> 1;
    return min(req[u][k], req[v - k2 + 1][k]);
}

void requests(ll u, ll v, ll m, ll n) {
    ll u_prev= 0, v_prev = 0, r_prev = 0;
    for (ll i = 1; i <= m; ++i) {
        r_prev = rmq(u - 1, v - 1);
        u_prev = u;
        v_prev = v;
        u = ((17 * u + 751 + r_prev + 2 * i) % n) + 1;
        v = ((13 * v + 593 + r_prev + 5 * i) % n) + 1;
    }
    cout << u_prev << " " << v_prev << " " << r_prev;
}

void commands() {
    ll n, m, a_1;
    cin >> n >> m >> a_1;
    ll u_1, v_1;
    cin >> u_1 >> v_1;

    fill_a(a_1, n);
    fill_req(n);
    requests(u_1, v_1, m, n);
}

int main() {
    commands();
    return 0;
}