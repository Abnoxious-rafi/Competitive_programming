//               |******In the name of ALLAH,the Beneficent,the Merciful******|
// coded by Rafi

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using lll = __int128_t;

#define Taratari ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

const int N = 2500 + 9, mod = 1e9 + 7;
const long long inf = 1e15;
int n, m;
vector<tuple<int, int, ll>> edges;
vector<ll> dist(N, inf); // store the shortest distance for sorce

ll belmen_ford(int source)
{
    dist[source] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (auto x : edges)
        {
            int u, v;
            ll w;
            tie(u, v, w) = x;
            if (dist[u] != inf && dist[u] + w < dist[v])
            {
                if (i == n)
                    return inf; // return infinity while negetive cycle is found

                dist[v] = dist[u] + w;
            }
        }
    }
    return dist[n];
}
template <typename T>
void solve(T case_number)
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }
    ll ans = belmen_ford(1);
    if (ans != inf)
        cout << -ans << endl;
    else
        cout << -1 << endl;
}

int main()
{
    Taratari;
    int Testcase = 1, index = 1;
    // cin >> Testcase;
    while (Testcase--)
    {
        // cout << "Case " << index << ": ";
        solve(index);
        index++;
    }

    return 0;
}
