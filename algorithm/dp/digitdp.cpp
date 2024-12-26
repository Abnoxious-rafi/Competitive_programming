//               |******In the name of ALLAH,the Beneficent,the Merciful******|
// coded by Rafi

// count the numbers form l to r where sum of digits is x

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
// using ll = __int128_t;

// functions:
// std::ostream &operator<<(std::ostream &dest, __int128_t value);

#define Taratari ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define endl "\n"

const int N = 2e5 + 9, inf = INT_MAX, mod = 1e9 + 7;

int check(string s, int x)
{
    int k = 0;
    for (int i = 0; i < s.size(); i++)
        k += (s[i] - '0');
    return k == x;
}
ll dp[1000][300][2];
ll digitdp(string &num, int n, int x, bool tight) //x -> property of query
{
    ll upperlim = (tight) ? num[num.size() - n] - '0' : 9;
    if (x < 0)
        return 0;
    if (n == 1)
    {
        if (x >= 0 && x <= upperlim)
            return 1;
        return 0;
    }
    if (dp[n][x][tight] != -1)
        return dp[n][x][tight];
    ll &ans = dp[n][x][tight] = 0;
    for (int digit = 0; digit <= upperlim; digit++)
        ans += digitdp(num, n - 1, x - digit, tight & (digit == upperlim));
    return ans;
}
ll countDigitSum(string &num, int x)
{
    int len = num.size();
    memset(dp, -1, sizeof dp);
    return digitdp(num, len, x, 1);
}
void solve(int case_number)
{
    string s1, s2;
    int x;
    cin >> s1 >> s2 >> x;
    cout << countDigitSum(s2, x) - countDigitSum(s1, x) + check(s1, x) << endl;
}

int main()
{
    Taratari;
    int Testcase = 1, index = 1;
    cin >> Testcase;
    while (Testcase--)
    {
        solve(index);
        // memset(dp, -1, sizeof dp);
        // cout << "Case " << index << ": ";
    }

    return 0;
}

// std::ostream &
// operator<<(std::ostream &dest, __int128_t value)
// {
//   std::ostream::sentry s(dest);
//   if (s)
//   {
//     __uint128_t tmp = value < 0 ? -value : value;
//     char buffer[128];
//     char *d = std::end(buffer);
//     do
//     {
//       --d;
//       *d = "0123456789"[tmp % 10];
//       tmp /= 10;
//     } while (tmp != 0);
//     if (value < 0)
//     {
//       --d;
//       *d = '-';
//     }
//     int len = std::end(buffer) - d;
//     if (dest.rdbuf()->sputn(d, len) != len)
//     {
//       dest.setstate(std::ios_base::badbit);
//     }
//   }
//   return dest;
// }
