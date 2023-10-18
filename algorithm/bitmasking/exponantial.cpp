#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll iterator_pow(ll a, ll b)
{
    //a%=module;
    //a=iterator_pow(x,y);(if a is greater,, like 2^1024.)
    ll ans = 1;
    while (b > 0)
    {
        if (b & 1)
        {
            ans *= a; // %module;
        }
        a *= a; //%module;
        b = b >> 1;
    }
    return ans;
}
void solve()
{
    int n,k;
    cin>>n>>k;
    cout<<iterator_pow(n,k)<<endl;
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