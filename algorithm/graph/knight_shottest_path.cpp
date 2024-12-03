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


//https://www.spoj.com/problems/NAKANJ/

string change(string temp, int i, int j)
{
     temp[0] += i;
     temp[1] += j;
     return temp;
}
template <typename T>
void solve(T case_number)
{
     string s1, s2;
     cin >> s1 >> s2;
     map<string, int> vis;
     queue<string> q;
     q.push(s1);
     while (!q.empty())
     {
          if(q.front()==s2)
          break;
          string temp = q.front();
          if (temp[0] + 2 <= 'h')
          {
               if (temp[1] + 1 <= '8')
               {
                    string k = change(temp, 2, 1);
                    if (vis[k] == 0)
                         q.push(k), vis[k] = vis[q.front()] + 1;
               }
               if (temp[1] - 1 > '0')
               {
                    string k = change(temp, 2, -1);
                    if (vis[k] == 0)
                         q.push(k), vis[k] = vis[q.front()] + 1;
               }
          }
          if (temp[0] - 2 >= 'a')
          {
               if (temp[1] + 1 <= '8')
               {
                    string k = change(temp, -2, 1);
                    if (vis[k] == 0)
                         q.push(k), vis[k] = vis[q.front()] + 1;
               }
               if (temp[1] - 1 > '0')
               {
                    string k = change(temp, -2, -1);
                    if (vis[k] == 0)
                         q.push(k), vis[k] = vis[q.front()] + 1;
               }
          }
          if (temp[1] + 2 <= '8')
          {
               if (temp[0] + 1 <= 'h')
               {
                    string k = change(temp, 1, 2);
                    if (vis[k] == 0)
                         q.push(k), vis[k] = vis[q.front()] + 1;
               }
               if (temp[0] - 1 >= 'a')
               {
                    string k = change(temp, -1, 2);
                    if (vis[k] == 0)
                         q.push(k), vis[k] = vis[q.front()] + 1;
               }
          }
          if (temp[1] - 2 > '0')
          {
               if (temp[0] + 1 <= 'h')
               {
                    string k = change(temp, 1, -2);
                    if (vis[k] == 0)
                         q.push(k), vis[k] = vis[q.front()] + 1;
               }
               if (temp[0] - 1 >= 'a')
               {
                    string k = change(temp, -1, -2);
                    if (vis[k] == 0)
                         q.push(k), vis[k] = vis[q.front()] + 1;
               }
          }
          q.pop();
     }
     cout<<vis[s2]<<endl;
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