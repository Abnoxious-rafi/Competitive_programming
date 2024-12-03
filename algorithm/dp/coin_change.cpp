#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    long long dfs(vector<int> &coins, int amount, vector<int> &dp)
    {
        if (amount <= 0)
            return 0;
        if (dp[amount] != -1)
            return dp[amount];
        long long ans = INT_MAX;
        for (auto child : coins)
        {
            if (amount - child >= 0)
            ans = min(ans, 1 + dfs(coins, amount - child, dp));
        }
        dp[amount] = ans;
        return ans;
    }
    int coinChange(vector<int> &coins, int amount)
    {
        if(amount==0)
        return 0;
        vector<int> dp(100009, -1);
        sort(coins.begin(), coins.end());
        int ans = dfs(coins, amount, dp);
        return (ans <= 0 || ans == INT_MAX) ? -1 : ans;
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
