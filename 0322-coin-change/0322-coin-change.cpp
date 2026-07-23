class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {

        //1D dp
        
        const int INF = 1e9;

        vector<int> dp(amount + 1, INF);
        dp[0] = 0;

        for (int coin : coins) {

            for (int j = coin; j <= amount; j++) {

                dp[j] = min(dp[j], 1 + dp[j - coin]);

            }
        }

        return dp[amount] == INF ? -1 : dp[amount];
    }
};