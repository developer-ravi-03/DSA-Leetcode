class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        // space optimisation 
        vector<int> next(n + 1, 0);
        vector<int> curr(n + 1, 0);

        for (int idx = n - 1; idx >= 0; idx--) {

            for (int prevIdx = idx - 1; prevIdx >= -1; prevIdx--) {

                int skip = next[prevIdx + 1];

                int take = 0;

                if (prevIdx == -1 || nums[prevIdx] < nums[idx]) {
                    take = 1 + next[idx + 1];
                }

                curr[prevIdx + 1] = max(skip, take);
            }

            next = curr;
        }

        return next[0];
    }
};