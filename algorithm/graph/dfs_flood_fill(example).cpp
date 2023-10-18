#include <iostream>
#include <vector>
using namespace std;

const int N = 1e5;
vector<int> g[N];
bool visited[N];

int dfs(int vertex)
{
    // section 1***
    visited[vertex] = true;
    for (auto child : g[vertex])
    {

        // section 2***
        if (!visited[child])
            dfs(child);

        // section 3***
    }

    // section 4***
}

vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
{
    int row=image[0].size();
}

int main()
{
    int vertex, edge;

    cin >> vertex >> edge;
    for (int i = 0; i < edge; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;

        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }
}