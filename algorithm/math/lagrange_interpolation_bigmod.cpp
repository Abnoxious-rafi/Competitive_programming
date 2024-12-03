#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MOD = 1e9 + 7;

// Modular exponentiation
ll bigmod(long long x, unsigned ll y, ll p) {
    ll res = 1;
    x = x % p;
    if (x == 0) return 0;
    while (y > 0) {
        if (y & 1) 
            res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}

//computes sumation(i^k) where 1<=i<=1e9 and k<=1e6;
// Compute the Lagrange llerpolation
ll Lagrange(const vector<ll> &p, long long x, ll a = 0, ll d = 1) {
    ll n = p.size() - 1;
    if (a == 0 && d == 1 && x <= n) return p[x];

    vector<ll> pref(n + 1, 1), suf(n + 1, 1);
    for (ll i = 0; i < n; i++) pref[i + 1] = (1LL * pref[i] * ((x - (a + 1LL * d * i)) % MOD + MOD) % MOD) % MOD;
    for (ll i = n; i > 0; i--) suf[i - 1] = (1LL * suf[i] * ((x - (a + 1LL * d * i)) % MOD + MOD) % MOD) % MOD;

    vector<ll> fact(n + 1, 1), finv(n + 1, 1);
    for (ll i = 1; i <= n; i++) fact[i] = (1LL * fact[i - 1] * (1LL * d * i % MOD) % MOD) % MOD;
    finv[n] = bigmod(fact[n], MOD - 2, MOD);
    for (ll i = n; i >= 1; i--) finv[i - 1] = (1LL * finv[i] * (1LL * d * i % MOD) % MOD) % MOD;

    ll ans = 0;
    for (ll i = 0; i <= n; i++) {
        ll tmp = (1LL * p[i] * pref[i] % MOD) * (1LL * suf[i] * finv[i] % MOD) % MOD;
        tmp = (1LL * tmp * finv[n - i] % MOD) % MOD;
        if ((n - i) & 1) ans = (ans - tmp + MOD) % MOD;
        else ans = (ans + tmp) % MOD;
    }

    return ans;
}

int main() {
    ll n, k;
    cin >> n >> k;
    vector<ll> p;
    ll sum = 0;
    p.push_back(0);
    for (ll i = 1; i <= k + 1; i++) {
        sum = (sum + bigmod(i, k, MOD)) % MOD;//i^k
        p.push_back(sum);
    }
    cout << Lagrange(p, n) << '\n';
    return 0;
}