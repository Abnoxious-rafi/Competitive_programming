#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll stirling(int n, int k, map<pair<int, int>, ll> S)
{
    if (n == k || k == 1)
        return 1;
    if (S[{n, k}] > 0)
        return S[{n, k}];
    return S[{n, k}] = stirling(n - 1, k - 1, S) + k * stirling(n - 1, k, S);
}
void solve()
{
    map<pair<int, int>, ll> S;
    int n, k;
    cin >> n >> k;
    cout << "we can split into " << k << " set of " << n << " numbers are " << stirling(n, k, S) << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1, i = 1;
    cin >> t;
    while (t--)
    {
        solve();
        i++;
    }
    return 0;
}