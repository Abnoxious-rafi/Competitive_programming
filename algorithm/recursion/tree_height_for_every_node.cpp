#include <bits/stdc++.h>
#include <vector>
using namespace std;
int i = 1;
class Solution
{
private:
    map<int, vector<int>> ans;
    vector<int> in, out;

public:
    void dfs1(vector<int> v[], int u, int parent)
    {
        in[u] = 0;
        for (int child : v[u])
        {
            if (child == parent)
                continue;
            dfs1(v, child, u);
            in[u] = max(in[u], 1 + in[child]);
        }
    }
    void dfs2(vector<int> v[], int u, int parent)
    {
        int mx1 = -1, mx2 = -1;
        for (int child : v[u])
        {
            if (child == parent)
                continue;
            if (in[child] >= mx1)
            {
                mx2 = mx1;
                mx1 = in[child];
            }
            else if (in[child] > mx2)
                mx2 = in[child];
        }

        for (int child : v[u])
        {
            if (child == parent)
                continue;

            int longest = mx1;
            if (mx1 == in[child])
                longest = mx2;
            out[child] = 1 + max(out[u], 1 + longest);
            dfs2(v, child, u);
        }
    }
    vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges)
    {
        vector<int> graph[n + 10];
        set<int> s;
        for (auto it : edges)
        {
            s.insert(it[0]);s.insert(it[1]);
            graph[it[0]].push_back(it[1]);
            graph[it[1]].push_back(it[0]);
        }
        in.resize(n + 1, 0);
        out.resize(n + 1, 0);
        dfs1(graph, *s.begin(), 0);
        dfs2(graph, *s.begin(), 0);
        for (auto it : s)
            ans[max(in[it],out[it])].push_back(it);
        for(auto it:ans)
            return it.second;
    return graph[0];
    }
};

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> grid;
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        vector<int> temp{a, b};
        grid.push_back(temp);
    }
    Solution S;
    vector<int> k = S.findMinHeightTrees(n, grid);

    for (auto it : k)
        cout << it << " ";
    cout << endl;
}
