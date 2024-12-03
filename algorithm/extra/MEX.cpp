#include<bits/stdc++.h>
using namespace std;
class Mex {
public:
    map<int, int> frequency;
    set<int> missing_numbers;
    vector<int> A;

    Mex(vector<int> const& A) : A(A) {
        for (int i = 0; i <= A.size(); i++)
            missing_numbers.insert(i);

        for (int x : A) {
            ++frequency[x];
            missing_numbers.erase(x);
        }
    }

    int mex() 
    {
        return *missing_numbers.begin();
    }

    void update(int idx, int new_value) {
        if (--frequency[A[idx]] == 0)
            missing_numbers.insert(A[idx]);
        A[idx] = new_value;
        ++frequency[new_value];
        missing_numbers.erase(new_value);
    }
};

void solve()
{
    vector<int>v;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        v.push_back(x);
    }
    Mex m(v);
    cout<<m.mex()<<endl;
    m.update(0,4);
    cout<<m.mex()<<endl;
}
int main()
{
    int testcase=1;
    cin>>testcase;
    while(testcase--)
    solve();
}