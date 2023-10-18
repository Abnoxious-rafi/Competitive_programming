#include <bits/stdc++.h>
using namespace std;
vector<string> v;

void func(int &opening, int &closing, string &s, int n)
{
  if (opening == n && closing == n)
    v.push_back(s);

  if (opening < n)
  {
    s.push_back('(');
    opening++;
    func(opening, closing, s, n);
  }

  if (closing < opening)
  {
    s.push_back(')');
    closing++;
    func(opening, closing, s, n);
  }

  if (s[opening + closing - 1] == '(')
    opening--;
  else
    closing--;
  if (s.size() > 0)
    s.pop_back();
}

vector<string> generate_paranthesis(int n)
{
  string s;
  int opening = 0, closing = 0;
  func(opening, closing, s, n);

  for (auto it : v)
    cout << it << endl;
  return v;
}
void solve()
{
  int n;
  cin >> n;
  generate_paranthesis(n);
}
int main()
{
  int t;
  solve();
}
