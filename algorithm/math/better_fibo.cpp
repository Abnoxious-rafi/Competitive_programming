#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define ULL unsigned long long 
void mul(ULL a[][2] , ULL b[][2])
{
    ULL res[2][2];
    memset(res , 0 , sizeof res);
    for(int i = 0 ; i < 2 ; i ++)
        for(int j = 0 ; j < 2 ; j++)
            for(int k = 0 ; k < 2 ; k++)
                res[i][j] = (res[i][j] + a[i][k]*b[k][j]) % MOD;
    for(int i = 0 ; i < 2 ; i++)
        for(int j = 0 ; j < 2 ; j++)
            a[i][j] = res[i][j];
}
ULL  power( ULL  n)
{
    ULL  fib[2][2] = { {1 , 1} , { 1 , 0}},temp[2][2] = { {1 , 0 } , { 0 , 1}};
    while(n)
    {
        if(n&1)
            mul(temp , fib);
        mul(fib , fib);
        n>>=1;
    }
    return temp[0][1];
}
int main()
{
    int t=1;
    //cin>>t;
    while(t--)
    {
        ULL l;
        cin>>l;
        cout<<(power(l) + MOD)%MOD<<endl;
    }
    return 0;
}
/*
    |-     -| n      |-           -|
    |  1  0 |     =  |  Fn+1  Fn   |
    |  0  1 |        |  Fn    Fn-1 |
    |-     -|        |-           -|
*/
