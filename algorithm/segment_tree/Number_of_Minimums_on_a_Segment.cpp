#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back

#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define rsort(x) sort(x.begin(), x.end())
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) a *b / __gcd(a, b)

// First greedy
// Use sorting
// Use dp [dynamic programming]
// Use recursive
// Use dfs
// Use math
// Use bit masking
// Make equation sorter[a.u - b.u < a.v - b.vqe]
int tree[300000];
vector<pair<int, int>> store(300000, {INT_MAX, 0});
int segment_tree(int a[], int index, int begin, int end)
{
     if (begin == end)
     {
          tree[index] = a[end];
          store[index].first = a[end];
          store[index].second = 1;
          return tree[index];
     }

     int mid, left, right;
     left = index * 2;
     right = index * 2 + 1;

     mid = ((begin + end) / 2);
     segment_tree(a, left, begin, mid);
     segment_tree(a, right, mid + 1, end);
     tree[index] = min(tree[left], tree[right]);
     store[index].first = tree[index];
     store[index].second = ((store[index].first == tree[left]) ? store[left].second : 0) + ((store[index].first == tree[right]) ? store[right].second : 0);
     return tree[index];
}
pair<int, int> range(int begin, int end, int rfirst, int rsecond, int index)
{
     if (end < rfirst || begin > rsecond)
          return {INT_MAX, 0};
     if (begin >= rfirst && end <= rsecond)
          return {tree[index], store[index].second};
     else
     {
          int left = index * 2;
          int right = left + 1;
          int mid = (begin + end) / 2;
          pair<int, int> p1, p2;
          p1 = range(begin, mid, rfirst, rsecond, left);
          p2 = range(mid + 1, end, rfirst, rsecond, right);
          int k = min(p1.first, p2.first);
          int l = ((p1.first == k) ? p1.second : 0) + ((p2.first == k) ? p2.second : 0);
          return {k, l};
     }
}
int change(int a[], int index, int begin, int end, int point, int value)
{
     if (begin == point && end == point)
     {
          a[begin] = value;
          tree[index] = value;
          store[index].first = value;
          store[index].second = 1;
          return value;
     }
     else if (begin <= point && end >= point)
     {
          int left = index * 2;
          int right = left + 1;
          int mid = (begin + end) / 2;
          change(a, left, begin, mid, point, value);
          change(a, right, mid + 1, end, point, value);
          tree[index] = min(tree[left], tree[right]);
          store[index].first = tree[index];
          store[index].second = ((store[index].first == tree[left]) ? store[left].second : 0) + ((store[index].first == tree[right]) ? store[right].second : 0);
          return tree[index];
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
          {
               change(a, 1, 1, n, x + 1, y);
          }
          else
          {
               pair<int, int> p = range(1, n, x + 1, y, 1);
               cout << p.first << " " << p.second << endl;//minimum number ans number of minimum number
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
