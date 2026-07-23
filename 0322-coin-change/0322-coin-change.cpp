class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {

        int n = coins.size();
        const int INF = 1e9;

        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, INF));

        // Base case
        for(int i = 0; i <= n; i++)
            dp[i][0] = 0;

        for(int i = n - 1; i >= 0; i--) {

            for(int j = 1; j <= amount; j++) {

                int take = INF;

                if(coins[i] <= j)
                    take = 1 + dp[i][j - coins[i]];

                int skip = dp[i + 1][j];

                dp[i][j] = min(take, skip);
            }
        }

        if(dp[0][amount] >= INF)
            return -1;

        return dp[0][amount];
    }
};