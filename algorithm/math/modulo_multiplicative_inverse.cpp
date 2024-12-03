//               |******In the name of ALLAH,the Beneficent,the Merciful******|
// coded by Rafi
#include <bits/stdc++.h>
// #include &lt;bits/stdc++.h&gt;

using namespace std;
using ll = long long;
using ull = unsigned long long;

#define Taratari ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#define yes printf("YES\n")
#define no printf("NO\n")
#define pi 2 * acos(0.0)
#define all(v) v.begin(), v.end()
const int N = 3e5 + 10;

ll sroot(ll n) // eficient sqrt()
{
    ll x = sqrt(n);
    while (x * x < n)
        x++;
    while (x * x > n)
        --x;
    return x;
}

ll mul(ll a, ll b, ll mod) // a*b %mod can multiply upto 10^18
{
    return __int128(a) * b % mod;
}

ll power(ll a, ll b, ll mod) // a^b %mod
{
    ll ans = 1;
    while (b != 0)
    {
        if (b & 1)
        {
            ans = mul(ans, a, mod) % mod;
        }
        b >>= 1;
        a = mul(a, a, mod) % mod;
    }
    return ans;
}

ll inverse(ll b, ll mod) // (1/b)%mod
{
    return power(b, mod - 2, mod);
}
template <typename T>
void solve(T case_number)
{
    // ll a, b,;
    // cin >> a >> b;
    // cout << power(a, b, mod) << endl;
    // cout << mul(a, b, mod) << endl;
    int n;
    cin >> n;
    ll a[n], b[n], mod = 998244353;
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        ans = (ans + ((power(2, n-1, mod)%mod) * a[i]) % mod) % mod;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
        ans = (ans + ((power(2, n-1, mod)%mod) * b[i]) % mod) % mod;
    }
    cout << mul(24, inverse(ans, mod), mod) << endl; // modulo multiplicative inverse
                                                    //(a/b)%mod -> a*(1/b)
}
int main()
{
    Taratari;
    int Testcase = 1, index = 1;
    // cin >> Testcase;
    while (Testcase--)
    {
        // cout << "Case " << index << ":" << endl;
        solve(index);
        index++;
    }

    return 0;
}
/*
data:
1)equal_range(.begin(),.end(),value);
     :: return iterator of lower_bound(value) & upper_bound(value);{pair maybe}
2)binary_search()
     :: return true or false
3)next_permutation()
     :: return next permutation of a string
4)unique()
     ::return iterator where single unique value are placed
     1 2 2 2 3 3 2 1 1 4 => 1 2 3 2 1 4 2 1 1 4
*/

// First greedy
// Use sorting
// Use dp [dynamic programming]
// Use recursive
// Use dfs
// Use math
// Use bit masking
// Make equation sorter[a.u - b.u < a.v - b.vqe]