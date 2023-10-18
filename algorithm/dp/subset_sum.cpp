#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
typedef long long ll;
int k;
int dp[100][20005];
#define v(a) scanf("%d", &a), v.push_back(a);

bool func(int sum, int i, vector<int> v)
{
    if (i <= 0)
        return false;
    if (sum == 0)
        return true;

    if (dp[i][sum] != -1)
        return dp[i][sum];

    bool k = 0;
    k |= func(sum, i - 1, v);
    if (sum - v[i] >= 0)
    k |= func(sum - v[i], i - 1, v);

    return dp[i][sum] = k;
}
void solve()
{
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++)
        v(k);

    int sum;
    cin >> sum;

    cout << func(sum, n - 1, v) << endl;
}
int main()
{
    int t = 1;
    cin >> t;
    while (t--)
    {
        memset(dp, -1, sizeof(dp));
        solve();
    }
    return 0;
}