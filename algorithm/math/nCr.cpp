#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll nCr(int n, int r)
{
    if (r > n)
        return 0;
    if (r == 0 || r == n)
        return 1;
    return nCr(n - 1, r - 1) + nCr(n - 1, r);
}
void solve()
{
    int n,r;
    cin>>n>>r;
    cout<<nCr(n,r)<<endl;
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