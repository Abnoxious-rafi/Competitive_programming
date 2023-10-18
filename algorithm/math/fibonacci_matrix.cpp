#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<vector<ll>> matrix_multiply(vector<vector<ll>> a, vector<vector<ll>> b)
{
    vector<vector<ll>> ans{{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
    for (int i = 1; i < 3; i++)
    {
        for (int j = 1; j < 3; j++)
        {
            ans[i][j] = 0;

            for (int k = 1; k < 3; k++)
            {
                ans[i][j] += (a[i][k] * b[k][j]);
            }
        }
    }

    return ans;
}

vector<vector<ll>> iterator_pow(vector<vector<ll>> a, ll b)
{
    // a%=module;
    // a=iterator_pow(x,y);(if a is greater,, like 2^1024.)
    vector<vector<ll>> ans{{0, 0, 0}, {0, 1, 1}, {0, 1, 0}};

    while (b > 0)
    {
        if (b & 1)
        {
            ans = matrix_multiply(ans, a); // %module;
        }
        a = matrix_multiply(a, a); //%module;
        b = b >> 1;
    }
    return ans;
}

void solve()
{
    vector<vector<ll>> x{{0, 0, 0}, {0, 1, 1}, {0, 1, 0}}, ans;
    int n;
    cin >> n;
    ll fn, fn_1, f1, f0;
    cin >> f0 >> f1;

    ans = iterator_pow(x, n - 1);
    // it will give n and n+1 th number;
    //if we use n-2 in iterator then it will give n-1 and n th number 

    fn = ans[1][1] * f1 + ans[1][2] * f0;
    fn_1 = ans[2][1] * f1 + ans[2][2] * f0;

    cout<<fn_1<<" "<<fn<<endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1, i = 1;
    cin >> t;
    while (t--)
    {
        solve();
        i++;
    }
    return 0;
}