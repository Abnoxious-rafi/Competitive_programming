//               |******In the name of ALLAH,the Beneficent,the Merciful******|
// coded by Rafi
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

#define loop(x, n) for (int i = x, i < n; i++)
#define Taratari ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define yes printf("YES\n")
#define no printf("NO\n")
#define lcm(a, b) (a * b) / __gcd(a, b)

vector<pair<int, int>> traverse{{1, 0}, {0, 1}, {-1, 0}, {0, -1}, {-1, -1}, {-1, 1}, {1, 1}, {1, -1}};

int dfswater(int i_th_land, string s[], vector<vector<int>> &vis, int i, int j, int n, int m)
{
     if (i < 0 || i == n || j < 0 || j == m || vis[i][j] > 0 || s[i][j] == '1')
          return 0;
     vis[i][j] = i_th_land;
     int cnt = 1;
     for (auto it : traverse)
     {
          cnt += dfswater(i_th_land, s, vis, i + it.first, j + it.second, n, m);
     }
     return cnt;
}

int dfsland(int i_th_land, string s[], vector<vector<int>> &vis, int i, int j, int n, int m, vector<set<int>> &graph)
{
     if (i < 0 || i == n || j < 0 || j == m)
          return 0;
     if (s[i][j] == '0')
     {
          graph[i_th_land].insert(vis[i][j]);
          graph[vis[i][j]].insert(i_th_land);
          return 0;
     }
     if (vis[i][j] > 0)
          return 0;

     vis[i][j] = i_th_land;
     for (auto it : traverse)
          dfsland(i_th_land, s, vis, i + it.first, j + it.second, n, m, graph);
     return 0;
}
int dfs_for_path(vector<set<int>> &graph, int parent, int end, vector<int> &graph_vis, vector<int> &weigth)
{
     if (graph_vis[parent] == 1)
          return 0;
     if (parent == end)
          return 1;
     graph_vis[parent] = 1;

     for (auto child : graph[parent])
     {
          int cnt = dfs_for_path(graph, child, end, graph_vis, weigth);
          if (cnt > 0)
               return cnt + weigth[child];
     }
     return 0;
}
template <typename T>
void solve(T case_number)
{
     int n, m, p = 1, k;
     cin >> n >> m >> k;

     string s[n];
     vector<int> weigth(10090, 0);
     vector<vector<int>> vis(n, vector<int>(m, 0));
     vector<set<int>> graph(10090);

     for (int i = 0; i < n; i++)
          cin >> s[i];

     // aajaira kam
     for (int i = 0; i < n; i++)
          for (int j = 0; j < m; j++)
               if (s[i][j] == '#')
                    s[i][j] = '1';
               else if (s[i][j] == '.')
                    s[i][j] = '0';
     // change korte vallagtase nah


     // counting water and store them
     for (int i = 0; i < n; i++)
     {
          for (int j = 0; j < m; j++)
          {
               if (s[i][j] == '0')
               {
                    int cnt = dfswater(p, s, vis, i, j, n, m);
                    if (cnt > 0)
                         weigth[p] = cnt, p++;
               }
          }
     }

     // visiting land and making a graph connected land and water
     for (int i = 0; i < n; i++)
     {
          for (int j = 0; j < m; j++)
          {
               if (s[i][j] == '1' && vis[i][j] == 0)
                    dfsland(p, s, vis, i, j, n, m, graph), p++;
          }
     }

     // searching for path and counting water
     vector<int> graph_vis(p, 0);
     int save = dfs_for_path(graph, vis[0][0], vis[n - 1][m - 1], graph_vis, weigth) - 1;
     cout << save << endl;
     if (save <= k)
          cout << "YES" << endl;
     else
          cout << "NO" << endl;

     /*
     for (auto it : weigth)
          cout << it << " ";
     cout << endl
          << endl;
     for (auto it : vis)
     {
          for (auto jt : it)
               cout << jt << " ";
          cout << endl;
     }

     for (int i = 0; i < 100; i++)
     {
          if (graph[i].size() != 0)
          {
               cout << i << " -> " << endl;
               for (auto it : graph[i])
                    cout << it << " ";
               cout << endl;
          }
     }
     */
}

int main()
{
     Taratari;
     int Testcase = 1, index = 1;
     cin >> Testcase;
     while (Testcase--)
     {
          solve(index);
          index++;
     }

     return 0;
}
/*
data:
1)equal_range(.begin(),.end(),value);
     :: return iterator of lower_bound(value) & upper_bound(value);
2)binary_search()
     :: return true or false
3)next_permutation()
     :: return next permutation of a string
4)unique()
     ::return iterator where single unique value are placed
     1 2 2 2 3 3 2 1 1 4 => 1 2 3 2 1 4 2 1 1 4
*/


/*
#include <bits/stdc++.h>
using namespace std;

const int dx[] = {+1,-1,+0,+0,-1,+1,-1,+1}, dy[] = {+0,+0,+1,-1,+1,+1,-1,-1};
void solve(){
     int n, m, p = 1, k;
     cin >> n >> m >> k;

    vector<vector<char>> s(n, vector<char>(m));
     vector<int> weigth(200001, 0);
     vector<vector<int>> vis(n+1, vector<int>(m+1, 0));
     vector<set<int>> graph(200001);

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            char x; cin>>x;
            s[i][j] = x == '.' ? '0' : '1';
        }
    }
    auto is_valid = [&n, &m](int i, int j)->bool{
        return i >= 0 and i < n and j >= 0 and j < m;
    };
    function<int(int,int,int)> dfswater = [&](int i_th_land, int i, int j)->int{
        if (!is_valid(i, j) or vis[i][j] > 0 or s[i][j] == '1') return 0;
        vis[i][j] = i_th_land;
        int cnt = 1;
        for(int k = 0; k < 8; k++){
            int ni = i + dx[k];
            int nj = j + dy[k];
            if(is_valid(ni, nj) and vis[ni][nj] == 0 and s[ni][nj] != '1'){
                cnt += dfswater(i_th_land, ni, nj);
            }
        }
        return cnt;
    };
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (s[i][j] == '0'){
                int cnt = dfswater(p, i, j);
                if (cnt > 0)
                        weigth[p] = cnt, p++;
            }
        }
    }
    function<int(int,int,int)> dfsland = [&](int i_th_land, int i, int j)->int{
        if (s[i][j] == '0'){
            graph[i_th_land].insert(vis[i][j]);
            graph[vis[i][j]].insert(i_th_land);
            return 0;
        }
        if (vis[i][j] > 0) return 0;
        vis[i][j] = i_th_land;

        for(int k = 0; k < 8; k++){
            int ni = i + dx[k];
            int nj = j + dy[k];
            if(is_valid(ni, nj)) dfsland(i_th_land, ni, nj);
        }
        return 0;
    };

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (s[i][j] == '1' && vis[i][j] == 0)
                dfsland(p, i, j), p++;
        }
    }

    vector<int> graph_vis(p, 0);

    function<int(int,int)>dfs_for_path = [&](int parent, int end)->int{
        if (graph_vis[parent] == 1) return 0;
        if (parent == end) return 1;
        graph_vis[parent] = 1;

        for (auto child : graph[parent]){
            int cnt = dfs_for_path(child, end);
            if (cnt > 0)
                return cnt + weigth[child];
        }
        return 0;
    };

    int save = dfs_for_path(vis[0][0], vis[n - 1][m - 1]) - 1;

    if (save <= k) cout << "Yes\n";
    else cout << "No\n";
}

int32_t main(){
    cin.tie(0)->sync_with_stdio(false);
    int Testcase = 1;
    cin >> Testcase;
    while (Testcase--){
        solve();
    }
    return 0;
}
*/