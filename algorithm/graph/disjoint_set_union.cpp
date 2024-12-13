//               |******In the name of ALLAH,the Beneficent,the Merciful******|
// coded by Rafi

#include <bits/stdc++.h>
using namespace std;
// #include <ext/pb_ds/assoc_container.hpp> // Common file
// #include <ext/pb_ds/tree_policy.hpp>     // Including tree_order_statistics_node_update
//   #pragma comment(linxer, "/STACx:2000000") // use to increase stacx size
// using namespace __gnu_pbds; // use to maxe ordered_set

// #include &lt;bits/stdc++.h&gt;

using ll = long long;
using ull = unsigned long long;
using lll = __int128_t;

// functions :
std::ostream &operator<<(std::ostream &dest, __int128_t value);

const int N = 1e5 + 9, inf = INT_MAX, mod = 1e9 + 7;
int parent[N], total_size[N];

void make(int vertex)
{
    parent[vertex] = vertex;
    total_size[vertex] = 1;
}
int find_root(int vertex)
{
    if (parent[vertex] == vertex)
        return vertex;
    return parent[vertex] = find_root(parent[vertex]);
}
void joint(int left, int right)
{
    left = find_root(left);
    right = find_root(right);
    if (left != right)
    {
        if (total_size[left] < total_size[right])
            swap(left, right);
        parent[right] = left;
        total_size[left] += total_size[right];
    }
}
void solve(int case_number)
{
    // using this...connected component can be find
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        make(i);
    while (k--)
    {
        int u, v;
        cin >> u >> v;
        joint(u, v);
    }
    int connected_component = 0;
    for (int i = 1; i <= n; i++)
        if (parent[i] == i)
            connected_component++;
    cout << connected_component << endl;
}

int main()
{
    int Testcase = 1, index = 1;
    // cin >> Testcase;
    while (Testcase--)
    {
        // memset(dp, -1, sizeof dp);
        // cout << "Case " << index << ": ";
        solve(index);
        index++;
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
