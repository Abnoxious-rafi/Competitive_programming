

//the number of ways to rearrange the occurance not in its right place
//example : n man put there cap in a bin now how they take caps that is not their own....


#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll d[4000], m = 1000000007;
ll dege(int n)
{
    if (n == 1)
        return 0;
    else if (n == 0)
        return 1;
    if(d[n]>0)
    return d[n];

    return d[n] = (((n - 1) % m) * (((dege(n - 1) % m) + (dege(n - 2) % m)) % m)) % m;
}
void solve()
{
    int n;
    cin >> n;
    cout << (((n - 1) % m) * (((dege(n - 1) % m) + (dege(n - 2) % m)) % m)) % m << endl;
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