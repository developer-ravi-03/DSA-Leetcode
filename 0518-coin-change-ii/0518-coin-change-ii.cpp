class Solution {
public:
    
    int helper(int i, int n, int amount, vector<int>& coins,vector<vector<int>> &dp) {
        if (amount == 0) {
            
            return 1;
        }
        if (i == n)
            return 0;

        if(dp[i][amount]!=-1) return dp[i][amount];

        int yes=0;
        if (coins[i] <= amount) {
            yes=helper(i, n, amount - coins[i], coins,dp);
        }
        int no=helper(i + 1, n, amount, coins,dp);
        return dp[i][amount]=yes+no;
    }

    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        return helper(0, n, amount, coins,dp);
         
    }
};