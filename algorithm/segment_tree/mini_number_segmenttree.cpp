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
int tree[1000000];
int segment_tree(int a[], int index, int begin, int end)
{
    if (begin == end)
    {
        tree[index] = a[end];
        return tree[index];
    }

    int mid, left, right;
    left = index * 2;
    right = index * 2 + 1;

    mid = ((begin + end) / 2);
    segment_tree(a, left, begin, mid);
    segment_tree(a, right, mid + 1, end);
    return tree[index] = min(tree[left], tree[right]);
}
int range(int begin, int end, int rfirst, int rsecond, int index)
{
    if (end < rfirst || begin > rsecond)
        return INT_MAX;
    if (begin >= rfirst && end <= rsecond)
        return tree[index];
    else
    {
        int left = index * 2;
        int right = left + 1;
        int mid = (begin + end) / 2;
        return min(range(begin, mid, rfirst, rsecond, left), range(mid + 1, end, rfirst, rsecond, right));
    }
}
int change(int a[], int index, int begin, int end, int point, int value)
{
    if (begin == point && end == point)
    {
        a[begin] = value;
        tree[index] = value;
        return value;
    }
    else if (begin <= point && end >= point)
    {
        int left = index * 2;
        int right = left + 1;
        int mid = (begin + end) / 2;
        change(a, left, begin, mid, point, value);
        change(a, right, mid + 1, end, point, value);
        return tree[index] = min(tree[left], tree[right]);
    }
    else
        return tree[index];
}

void solve()
{
    int n, q;
    cin >> n >> q;
    int a[n + 1];
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    segment_tree(a, 1, 1, n);
    while (q--)
    {
        int i, x, y;
        cin >> i >> x >> y;
        if (i == 1)
            change(a, 1, 1, n, x, y);
        else
            cout << range(1, n, x, y, 1) << endl;
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll testcase = 1, i = 1;
    cin >> testcase;
    while (testcase--)
    {
        for(int i=0;i<=100000;i++)
        tree[i]=0;
        solve();
    }
}
