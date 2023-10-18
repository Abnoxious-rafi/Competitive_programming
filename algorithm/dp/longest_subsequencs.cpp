#include <bits/stdc++.h>
using namespace std;
int p[1009][1009];
int lcs(int i,int j,string &s1,string &s2)
{
    int ans=0;
    if(i<0 || j<0)
    return 0;

    if(p[i][j]!= -1)
    return p[i][j];


    ans=max(ans,lcs(i-1,j,s1,s2));
    ans=max(ans,lcs(i,j-1,s1,s2));
    ans=max(ans,lcs(i-1,j-1,s1,s2)+(s1[i]==s2[j]));
    return p[i][j]=ans;
}

int longestCommonSubsequence(string text1, string text2)
{
    int i=text1.size(),j=text2.size();
    memset(p,-1,sizeof(p));
    return lcs(i-1,j-1,text1,text2);
}

int main()
{
    string text1,text2;
    cin>>text1>>text2;
    cout<<longestCommonSubsequence(text1,text2);
    return 0;
}
