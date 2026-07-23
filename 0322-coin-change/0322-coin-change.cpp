class Solution {
public:
  
    int helper(int i, int n, int amount, vector<int>& coins,vector<vector<int>> &dp) {
        if (amount == 0) {            
            return 0;
        }
        if (i == n)
            return 1e9;

        if(dp[i][amount]!=-1) return dp[i][amount];

        int yes=1e9;
        if (coins[i] <= amount) {
            yes=1+helper(i, n, amount - coins[i], coins,dp);
        }
        int no=helper(i + 1, n, amount, coins,dp);
        return dp[i][amount]=min(yes,no);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        int ans=helper(0, n, amount, coins,dp);
        return ans>=1e9?-1:ans;
    }
};