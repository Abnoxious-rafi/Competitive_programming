#include<bits/stdc++.h>
using namespace std;
int c=0;
pair<int, int> fib (int n) {
    if (n == 0)
        return {0, 1};
    auto p = fib(n >> 1);
    c++;
    int c = p.first * (2 * p.second - p.first);
    int d = p.first * p.first + p.second * p.second;     
    if (n & 1)
        return {d, c + d};
    else
        return {c, d};
}
int main()
{
    int n;
    cin>>n;
    pair<int,int>p=fib(n);
    cout<<c<<endl;
    cout<<p.first<<" "<<p.second<<endl;
}