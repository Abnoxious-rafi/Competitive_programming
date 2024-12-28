//               |******In the name of ALLAH,the Beneficent,the Merciful******|
// coded by Rafi

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

#define Taratari ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
// const int N = 2e5 + 9, inf = INT_MAX, mod = 1e9 + 7;
ll mod = 998244353;
vector<vector<ll>> expo(vector<vector<ll>> &a, ll b, int n, ll mod);
vector<vector<ll>> matrix_multiply(vector<vector<ll>> &a, vector<vector<ll>> &b, int n, ll mod);
template <typename T>
void solve(T case_number)
{
    ll n, k;
    cin >> n >> k;
    vector<vector<ll>> a(n, vector<ll>(n));

    //input
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];

    vector<vector<ll>> ans = expo(a, k, n, mod);

    //output
    for (int i = 0; i < n; i++, cout << endl)
        for (int j = 0; j < n; j++)
            cout << ans[i][j] << " ";
}

int main()
{
    Taratari;
    int Testcase = 1, index = 1;
    // cin >> Testcase;
    while (Testcase--)
    {
        // cout << "Case " << index << ": ";
        // memset(dp, -1, sizeof dp);
        solve(index);
        index++;
    }
    return 0;
}

vector<vector<ll>> expo(vector<vector<ll>> &a, ll b, int n, ll mod)
{
    vector<vector<ll>> ans(n, vector<ll>(n, 0));
    for (int i = 0; i < n; i++)
        ans[i][i] = 1;

    while (b != 0)
    {
        if (b & 1)
            ans = matrix_multiply(ans, a, n, mod); // (ans * a) % mod;
        a = matrix_multiply(a, a, n, mod);         //(a * a) % mod;
        b >>= 1;
    }
    return ans;
}

vector<vector<ll>> matrix_multiply(vector<vector<ll>> &a, vector<vector<ll>> &b, int n, ll mod)
{
    vector<vector<ll>> ans(n, vector<ll>(n, 0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int p = 0; p < n; p++)
                ans[i][j] = (ans[i][j] + a[i][p] * b[p][j]) % mod; // complexity n*m*k
    return ans;
}
