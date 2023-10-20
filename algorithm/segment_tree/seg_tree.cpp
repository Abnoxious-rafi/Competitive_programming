#include <iostream>
#include <math.h>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;
#define ll long long
#define en cout << endl
vector<int> v;
ll a[2000000], tree[9000000];

void seg_tre(int ind, int b, int e)
{
    if (b == e)
    {
        tree[ind] = a[b];
        return;
    }
    int left = ind * 2;
    int right = ind * 2 + 1;
    int mid = (b + e) / 2;
    seg_tre(left, b, mid);
    seg_tre(right, mid + 1, e);
    tree[ind] = tree[left] + tree[right];
}
ll update(int ind, int b, int e, int r, ll value)
{
    if (b == r && e == r)
    {
        a[begin] = value;
        tree[ind] = value;
        return value;
    }
    else if (b <= r && r <= e)
    {
        int left = ind * 2;
        int right = ind * 2 + 1;
        int mid = (b + e) / 2;
        update(left, b, mid, r, value);
        update(right, mid + 1, e, r, value);
        tree[ind] = tree[left] + tree[right];
    }
    else
    {
        return tree[ind];
    }
}

ll sub_seg_sum(int ind, int b, int e, int range_begin, int range_end)
{

    if (e < range_begin || b > range_end)
        return 0;
    else if (b >= range_begin && e <= range_end)
        return tree[ind];
    else
    {
        int left = ind * 2;
        int right = ind * 2 + 1;
        int mid = (b + e) / 2;
        return sub_seg_sum(left, b, mid, range_begin, range_end) + sub_seg_sum(right, mid + 1, e, range_begin, range_end);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    seg_tre(1, 1, n);
    while (q--)
    {
        int i, x, y;
        cin >> i >> x >> y;
        if (i == 1)
            update(1, 1, n, x+1 , y);
        else
            cout << sub_seg_sum(1, 1, n, x + 1, y) << endl;
    }
}
