#include <bits/stdc++.h>
#define ll long long
using namespace std;
void prefix_sum(vector<vector<ll>> &v)
{
    int n = v.size(), m = v[0].size();
    for (int i = 1; i < m; i++)
        v[0][i] += v[0][i - 1];
    for (int i = 1; i < n; i++)
        v[i][0] += v[i - 1][0];
    for (int i = 1; i < n; i++)
        for (int j = 1; j < m; j++)
            v[i][j] += (v[i - 1][j] + v[i][j - 1] - v[i - 1][j - 1]);
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<ll>> v;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> v[i][j];
}