#include <iostream>
#include <vector>
#include<set>
using namespace std;

const int N = 1e6;
vector<int> g[N];
bool visited[N];

void dfs(int vertex)
{
    //section 1***
    visited[vertex]=true;
    for (auto child : g[vertex])
    {
        
        //section 2***
        if(visited[child]==true)continue;
        dfs(child);

        //section 3***

    }

    //section 4***
}

int main()
{
    int vertex, edge;
    set<int>s;

    cin >> vertex >> edge;
    for (int i = 0; i < edge; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;

        s.insert(v1);
        s.insert(v2);

        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }

    int count=0;

    for(int it:s)
    {
        if(visited[it]==false)
        {
            dfs(it);
            count++;
        }
    }

    cout<<vertex-int(s.size())+count<<endl;
}