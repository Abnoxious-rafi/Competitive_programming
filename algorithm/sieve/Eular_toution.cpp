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
#define read(a) int a;cin>>a;

const int M = 5000001;
vector<int> store(M, 0);
void Eeular_toshion()
{
    for (int i = 1; i <= M; i++)
        store[i] = i;
    for (int i = 2; i <= M; i++)
    {
        if (store[i] == i)
            for (int j = 2 * i; j <= M; j += i)
                store[j] = (store[j] / i) * (i - 1);
        if (store[i] == i)
            store[i] = i - 1;
    }
}
template <typename T>
void solve(T case_number)
{
    read(i);
    cout << store[i] << endl;
}

int main()
{
    Taratari;
    Eeular_toshion();
    // for (int i = 1; i <= 20; i++)
    //      cout << i << " -> " << store[i] << " , " << pre[i] << endl;
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