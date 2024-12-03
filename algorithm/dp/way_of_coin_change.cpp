#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int dfs(vector<int> &coins, int amount, int index, vector<vector<int>> &dp)
    {
        cout<<amount<<" "<<index<<endl;
        if (amount == 0)
            return 1;
        if (dp[index][amount] != -1)
            return dp[index][amount];
        int way = 0;
        for (int it = index; it < coins.size(); it++)
        {
            if (amount - coins[it] >= 0)
                way += dfs(coins, amount - coins[it], it, dp);
        }
        return dp[index][amount] = way;
    }
    int coinChange(vector<int> &coins, int amount)
    {
        sort(coins.begin(), coins.end());
        vector<vector<int>> dp(301, vector<int>(5001, -1));
        return dfs(coins, amount, 0, dp);
    }
};
int main()
{
    int n, ammount;
    cin >> n >> ammount;
    vector<int> coins(n);
    for (auto &it : coins)
        cin >> it;
    Solution S;
    cout << S.coinChange(coins, ammount) << endl;
    return 0;
}
