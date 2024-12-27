//               |******In the name of ALLAH,the Beneficent,the Merciful******|
// coded by Rafi

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using lll = __int128_t;

#define Taratari ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define endl "\n"

const int N = 2e5 + 9, inf = INT_MAX, mod = 1e9 + 7, mod2 = 998244353;

std::ostream &
operator<<(std::ostream &dest, __int128_t value);

void matrix_multiply()
{
    int n, m, k;
    cin >> n >> k >> m;
    ll a[n][k], b[k][m];

    // first matrix of n,k
    for (int i = 0; i < n; i++)
        for (int j = 0; j < k; j++)
            cin >> a[i][j];

    // second matrix of k,m
    for (int i = 0; i < k; i++)
        for (int j = 0; j < m; j++)
            cin >> b[i][j];

    // ans matrix of n,m
    ll c[n][m];
    memset(c, 0, sizeof c);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            for (int p = 0; p < k; p++)
            {
                c[i][j] = (c[i][j] + a[i][p] * b[p][j]) % mod2; // complexity n*m*k
            }
        }
    }

    // output
    for (int i = 0; i < n; i++, cout << endl)
        for (int j = 0; j < m; j++)
            cout << c[i][j] << " ";
}
template <typename T>
void solve(T case_number)
{
    matrix_multiply();
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

std::ostream &
operator<<(std::ostream &dest, __int128_t value)
{
    std::ostream::sentry s(dest);
    if (s)
    {
        __uint128_t tmp = value < 0 ? -value : value;
        char buffer[128];
        char *d = std::end(buffer);
        do
        {
            --d;
            *d = "0123456789"[tmp % 10];
            tmp /= 10;
        } while (tmp != 0);
        if (value < 0)
        {
            --d;
            *d = '-';
        }
        int len = std::end(buffer) - d;
        if (dest.rdbuf()->sputn(d, len) != len)
        {
            dest.setstate(std::ios_base::badbit);
        }
    }
    return dest;
}
