//               |******In the name of ALLAH,the Beneficent,the Merciful******|
// coded by Rafi
 
#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp> // Common file
// #include <ext/pb_ds/tree_policy.hpp>     // Including tree_order_statistics_node_update
//   #pragma comment(linker, "/STACK:2000000") // use to increase stack size
using namespace std;
// using namespace __gnu_pbds; // use to make ordered_set
 
// template <typename T>
// using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; // ordered set
// 	priority_queue<int, vector<int>, greater<int>> variable; for increasing order
 
using ll = long long;
 
#define all(v) v.begin(), v.end()
#define pr pair<ll, ll>
const ll N = 1e5 + 9, inf = LONG_MAX;
 
set<pr> s;
vector<ll> ans(N, inf);
vector<bool> vis(N, false);
vector<pr> graph[N];
 
void dijkstra_Algo(int src)
{
    s.insert(make_pair(0, src)); //(weight , sourse)
    ans[src] = 0; 
    while (!s.empty())
    {
        ll sourse = s.begin()->second, distance = s.begin()->first;
        s.erase(s.begin());
        if (vis[sourse] == true)
            continue;
        vis[sourse] = true;
        for (auto child : graph[sourse])
        {
            if (child.second + distance < ans[child.first])
            {
                ans[child.first] = child.second + distance;
                s.insert(make_pair(child.second + distance, child.first));
            }
        }
    }
}
void solve(int case_number)
{
    int n, m, sourse = 1;
    cin >> n >> m;
 
    for (int i = 0; i < m; i++)
    {
        ll x, y, weight;
        cin >> x >> y >> weight;
        graph[x].push_back(make_pair(y, weight));
    }
 
    dijkstra_Algo(sourse);
    for (int i = 1; i <= n; i++)
        cout << ans[i] << " ";
    cout << endl;
 
    //deleting for next testcase
    // for (int i = 0; i <= n; i++)
    // {
    //     graph[i].clear();
    //     ans[i] = inf;
    //     vis[i] = false;
    // }
    // s.clear();
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int testcase = 1, p = 1;
    // cin >> testcase;
    while (testcase--)
    {
        // cout << "Case " << p << ": " << endl;
        solve(p++);
    }
}
/*
data:
1)equal_range(.begin(),.end(),value);
     :: return iterator of lower_bound(value) & upper_bound(value);{pair maybe}
2)binary_search()
     :: return true or false
3)next_permutation()
     :: return next permutation of a string
4)unique()
     ::return iterator where single unique value are placed
     1 2 2 2 3 3 2 1 1 4 => 1 2 3 2 1 4 2 1 1 4
 
     ::we can use resize to get only unique value in vector
     => variable_name.resize(unique(v.begin(),v.end())-v.begin());
5)making structure:
     ::struct info
       {
        ll maximum;
        ll minimum;
       } tree[400009];
 
     ::accessing by tree[index].maximum,tree[index].minimum
6)priority queue:
     ::typedef data_type(pair<ll, pair<ll, ll>>) pi;
     ::priority_queue<pi, vector<pi>> p;                  -> "increasing order"
     ::priority_queue<pi, vector<pi>, greater<pi>> p;     -> "decreasing order"
7)__builtin_popcountll(number)
     ::count number of 1 in a number
 
8)o_set<data_type> variable;           -> kind of a set but can find the value in index
     ::variable.find_by_order(index)   -> find the value in index return iterator
     ::variable.order_of_key(value)    -> find number of value less then value
 
*/