#include <iostream>
#include <vector>
#include<algorithm>
const int N = 100;
using namespace std;
int main()
{
    int n;
    cin >> n;
    int p = 2 << n - 1;
    int a[n];
    for (int i = 0; i < n; ++i)
        cin >> a[i]; //   input
    vector<vector<int>> v;
    for (int i = 0; i < p; ++i)
    {
        vector<int> temp;
        for (int j = 0; j < n; ++j)
        {
            if (i & (1 << j))
                temp.push_back(a[j]);
        }
        v.push_back(temp);
    }
    for (auto it : v)
    {
        cout << "{ ";
        for (auto ele : it)
        {
            cout << ele << " ";
        }
        cout << "} " << endl;
    }
}
