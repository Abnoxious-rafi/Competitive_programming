#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back

#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define rsort(x) sort(x.begin(), x.end())
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) a *b / __gcd(a, b)
int mod = 998244353;
const int mx = 100000;

struct info
{
    ll segment, sufix, prefix, sum;
} Tree[mx * 3];

ll tree[1000000], sufix[1000000], prefix[1000000], sum[1000000];
ll segment_tree(ll a[], int index, int begin, int end)
{
    if (begin == end)
    {
        tree[index] = a[end];
        sufix[index] = a[end];
        prefix[index] = a[end];
        sum[index] = a[end];
        return tree[index];
    }

    int mid, left, right;
    left = index * 2;
    right = index * 2 + 1;

    mid = ((begin + end) / 2);
    segment_tree(a, left, begin, mid);
    segment_tree(a, right, mid + 1, end);
    tree[index] = max({tree[left], tree[right], prefix[right] + sufix[left]});
    prefix[index] = max(prefix[left], sum[left] + prefix[right]);
    sufix[index] = max(sufix[right], sum[right] + sufix[left]);
    sum[index] = sum[left] + sum[right];
    return tree[index];
}

ll change(ll a[], int index, int begin, int end, ll point, ll value)
{
    if (begin == point && end == point)
    {
        a[begin] = value;
        tree[index] = value;
        sufix[index] = value;
        prefix[index] = value;
        sum[index] = value;
        return value;
    }
    else if (begin <= point && end >= point)
    {
        int left = index * 2;
        int right = left + 1;
        int mid = (begin + end) / 2;
        change(a, left, begin, mid, point, value);
        change(a, right, mid + 1, end, point, value);
        tree[index] = max({tree[left], tree[right], prefix[right] + sufix[left]});
        prefix[index] = max(prefix[left], sum[left] + prefix[right]);
        sufix[index] = max(sufix[right], sum[right] + sufix[left]);
        sum[index] = sum[left] + sum[right];
        return tree[index];
    }
    else
        return tree[index];
}

vector<ll> range(int begin, int end, int rfirst, int rsecond, int index)
{
    if (end < rfirst || begin > rsecond)
        return {LONG_MIN, LONG_MIN, LONG_MIN, LONG_MIN};
    if (begin >= rfirst && end <= rsecond)
        return {tree[index], prefix[index], sufix[index], sum[index]};
    else
    {
        int left = index * 2;
        int right = left + 1;
        int mid = (begin + end) / 2;
        vector<ll> v1 = range(begin, mid, rfirst, rsecond, left), v2 = range(mid + 1, end, rfirst, rsecond, right);
        return {max({v1[0], v2[0], v2[1] + v1[2]}), max(v1[1], v1[3] + v2[1]), max(v2[2], v2[3] + v1[2]), v1[3] + v2[3]};
    }
}
void solve()
{
    int n, q;
    cin >> n >> q;
    ll a[n + 1];
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    segment_tree(a, 1, 1, n);

    while (q--)
    {
        ll i, x, y;
        cin >> i >> x >> y;
        if (i == 1)
            change(a, 1, 1, n, x + 1, y);
        else
        {
            vector<ll> v = range(1, n, x + 1, y, 1);
            cout << v[0] << endl;
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll testcase = 1, i = 1;
    // cin >> testcase;
    while (testcase--)
    {
        solve();
    }
}
