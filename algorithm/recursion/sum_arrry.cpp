#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define arr(x, n)               \
    ll x[n];                    \
    for (int i = 0; i < n; i++) \
        cin >> x[i];

#define iput(x, n)              \
    for (int i = 0; i < n; i++) \
    {                           \
        int value;              \
        cin >> value;           \
        x.pb(value);            \
    }

#define oput(x, n)              \
    for (int i = 0; i < n; i++) \
    {                           \
        cout << x[i] << " ";    \
    }                           \
    cout << endl;

#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define rsort(x) sort(x.begin(), x.end())
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) a *b / __gcd(a, b)

int mod = 998244353;

// First greedy
// Use sorting
// Use dp [dynamic programming]
// Use recursive
// Use dfs
// Use math
// Use bit masking
// Make equation sorter[a.u - b.u < a.v - b.vqe]

int z;
vector<ll>maybe_ans;
int i_know_recurtion(ll sum, int i, int n, ll a[])
{
    
    if (sum == 0)
        return z=0;
    else if (sum < 0 || i == n)
        return z=-1; 
    maybe_ans.push_back(a[i]);
    if (i_know_recurtion(sum - a[i], i + 1, n, a) == 0)
        return z=0;
    maybe_ans.pop_back();
    if (i_know_recurtion(sum, i + 1, n, a) == 0)
        return z=0;
    return z;
}

void solve()
{
    int n;
    ll sum;
    cin >> n >> sum;
    arr(a, n);
    sort(a, a + n);
    if(i_know_recurtion(sum,0,n,a)==0)
    cout<<"YES"<<endl;
    else
    cout<<"NO"<<endl;
    for(int i=0;i<maybe_ans.size();i++)
    cout<<maybe_ans[i]<<" ";
    cout<<endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll testcase = 1, i = 1;
    // cin >> testcase;
    while (testcase--)
        solve();
}
