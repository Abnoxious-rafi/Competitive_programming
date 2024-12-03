#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define second_grandmaster ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define endl '\n'

const int N = 1e6 + 9;
#define MAX 20 // (1 + (1 << 6)) // Why? :D
#define inf 0x7fffffff
int tree[10], arr[10], lazy[10];

struct info
{
    int a = 0, c = 0, g = 0, t = 0;
} hs[N];

std::ostream &
operator<<(std::ostream &dest, __int128_t value);

void solve(int case_num)
{

    
}

int main()
{
    second_grandmaster;
    int T = 1, i = 1;
    cin >> T;
    while (T--)
    {
        solve(i);
        i++;
    }

    return 0;
}

std::ostream &
operator<<(std::ostream &dest, __int128_t value)
{
    std::ostream::sentry s(dest);
    if (s)
    {
        __uint128_t tmp = value < 0 ? -value : value;
        char buffer[128];
        char *d = std::end(buffer);
        do
        {
            --d;
            *d = "0123456789"[tmp % 10];
            tmp /= 10;
        } while (tmp != 0);
        if (value < 0)
        {
            --d;
            *d = '-';
        }
        int len = std::end(buffer) - d;
        if (dest.rdbuf()->sputn(d, len) != len)
        {
            dest.setstate(std::ios_base::badbit);
        }
    }
    return dest;
}

void build_tree(int node, int a, int b)
{
    if (a > b)
        return; // Out of range

    if (a == b)
    {                        // Leaf node
        tree[node] = arr[a]; // Init value
        return;
    }

    build_tree(node * 2, a, (a + b) / 2);         // Init left child
    build_tree(node * 2 + 1, 1 + (a + b) / 2, b); // Init right child

    tree[node] = max(tree[node * 2], tree[node * 2 + 1]); // Init root value
}

void update_tree(int node, int a, int b, int i, int j, int value)
{

    if (lazy[node] != 0)
    {                             // This node needs to be updated
        tree[node] += lazy[node]; // Update it

        if (a != b)
        {
            lazy[node * 2] += lazy[node];     // Mark child as lazy
            lazy[node * 2 + 1] += lazy[node]; // Mark child as lazy
        }

        lazy[node] = 0; // Reset it
    }

    if (a > b || a > j || b < i) // Current segment is not within range [i, j]
        return;

    if (a >= i && b <= j)
    { // Segment is fully within range
        tree[node] += value;

        if (a != b)
        { // Not leaf node
            lazy[node * 2] += value;
            lazy[node * 2 + 1] += value;
        }

        return;
    }

    update_tree(node * 2, a, (a + b) / 2, i, j, value);         // Updating left child
    update_tree(1 + node * 2, 1 + (a + b) / 2, b, i, j, value); // Updating right child

    tree[node] = max(tree[node * 2], tree[node * 2 + 1]); // Updating root with max value
}

int power_upuery_tree(int node, int a, int b, int i, int j)
{

    if (a > b || a > j || b < i)
        return -inf; // Out of range

    if (lazy[node] != 0)
    {                             // This node needs to be updated
        tree[node] += lazy[node]; // Update it

        if (a != b)
        {
            lazy[node * 2] += lazy[node];     // Mark child as lazy
            lazy[node * 2 + 1] += lazy[node]; // Mark child as lazy
        }

        lazy[node] = 0; // Reset it
    }

    if (a >= i && b <= j) // Current segment is totally within range [i, j]
        return tree[node];

    int power_up1 = power_upuery_tree(node * 2, a, (a + b) / 2, i, j);         // power_upuery left child
    int power_up2 = power_upuery_tree(1 + node * 2, 1 + (a + b) / 2, b, i, j); // power_upuery right child

    int res = max(power_up1, power_up2); // Return final result

    return res;
}
