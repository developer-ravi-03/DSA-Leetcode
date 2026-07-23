class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {

        int n = coins.size();
        const int INF = 1e9;

        vector<int> next(amount + 1, INF);
        next[0] = 0;

        for (int i = n - 1; i >= 0; i--) {

            vector<int> curr(amount + 1, INF);
            curr[0] = 0;

            for (int j = 1; j <= amount; j++) {

                int take = INF;

                if (coins[i] <= j)
                    take = 1 + curr[j - coins[i]];

                int skip = next[j];

                curr[j] = min(take, skip);
            }

            next = curr;
        }

        return next[amount] == INF ? -1 : next[amount];
    }
};