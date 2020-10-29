#include <iostream>
#include <cmath>

using namespace std;
typedef long long ll;
const ll size = 10e6;

ll a[size], c[2 * size], res[size];

void fill_a(ll n, ll x, ll y, ll a_0) {
    a[0] = a_0;
    for (ll i = 1; i < n; ++i)
        a[i] = (x * a[i - 1] + y) % ll(pow(2, 16));
}

void fill_c(ll m, ll n, ll z, ll t, ll b_0) {
    c[0] = b_0 % n;
    for (ll i = 1; i < 2 * m + 1; ++i) {
        b_0 = (z * b_0 + t) % ll(pow(2, 30));
        c[i] = b_0 % n;
    }
}

ll RSQ(ll left, ll right) {
    if (left == 0)
        return res[right];
    else
        return res[right] - res[left - 1];
}

void request(ll m) {
    ll* sums = new ll[m];
    ll sum = 0;
    for (ll i = 0; i < m; ++i) {
        sums[i] = RSQ(min(c[2 * i], c[2 * i + 1]), max(c[2 * i], c[2 * i + 1]));
        sum += sums[i];
    }
    cout << sum;
}

void build(ll n) {
    res[0] = a[0];
    for (ll i = 1; i < n; ++i)
        res[i] = res[i - 1] + a[i];
}

void commands() {
    ll n, x, y, a_0;
    cin >> n >> x >> y >> a_0;
    ll m, z, t, b_0;
    cin >> m >> z >> t >> b_0;

    fill_a(n, x, y, a_0);
    fill_c(m, n, z, t, b_0);
    build(n);
    request(m);
}

int main() {
    commands();
    return 0;
}