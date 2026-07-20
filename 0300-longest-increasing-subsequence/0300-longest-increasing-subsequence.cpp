class Solution {
public:
    int solve(int idx, int prevIdx, int n, vector<int>& nums,
              vector<vector<int>>& dp) {
        if (idx == n)
            return 0;

        if (dp[idx][prevIdx + 1] != -1)
            return dp[idx][prevIdx + 1];

        int skip = solve(idx + 1, prevIdx, n, nums, dp);
        int take = 0;
        if (prevIdx == -1 || nums[prevIdx] < nums[idx])
            take = 1 + solve(idx + 1, idx, n, nums, dp);

        return dp[idx][prevIdx + 1] = max(take, skip);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        int prevIdx = -1;
        return solve(0, prevIdx, n, nums, dp);
    }
};