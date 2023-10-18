#include <iostream>
#include <vector>
using namespace std;

const int N = 1e3;

int graph_matrix[N][N];
vector<int> graph_list[N];

int main()
{
    int vertex, edge;
    cin >> vertex >> edge;

    for (int i = 0; i < edge; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;

        graph_matrix[v1][v2] = 1; // if weigth is given then  || graph_matrix[v1][v2]=weigth.....
        graph_matrix[v2][v1] = 1; //                          || graph_matrix[v2][v1]=weigth.....

        graph_list[v1].push_back(v2); // make vector<pair<int,int>>....and store the weigth in pair
        graph_list[v2].push_back(v1);
    }
}