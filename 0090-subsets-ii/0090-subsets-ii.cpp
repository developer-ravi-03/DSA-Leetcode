class Solution {
public:
    void solve(int index,vector<int>& tmp,vector<int>& nums,vector<vector<int>>& ans){
        if(index==nums.size()){
            ans.push_back(tmp);
            return;
        }
        tmp.push_back(nums[index]);
        solve(index+1,tmp,nums,ans);
        tmp.pop_back();

        //skip duplicate element
        int idx=index+1;
        while(idx<nums.size() && nums[idx]==nums[idx-1]){
            idx++;
        }
        solve(idx,tmp,nums,ans);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> tmp;
        solve(0,tmp,nums,ans);
        return ans;
    }
};