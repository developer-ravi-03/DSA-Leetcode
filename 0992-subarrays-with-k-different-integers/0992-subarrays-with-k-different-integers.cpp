class Solution {
public:
    int count(vector<int>& nums, int k) {
        if (k < 0)
            return 0;

        unordered_map<int, int> mp;
        int ctsubarr = 0;
        int low = 0;
        for (int high = 0; high < nums.size(); high++) {
            mp[nums[high]]++;
            while (mp.size() > k) {
                mp[nums[low]]--;
                if (mp[nums[low]] == 0) {
                    mp.erase(nums[low]);
                }
                low++;
            }
            ctsubarr += (high - low + 1);
        }
        return ctsubarr;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return count(nums, k) - count(nums, k - 1);
    }
};