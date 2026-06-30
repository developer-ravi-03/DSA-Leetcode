class Solution {
public:
    void solve(int index,vector<int>& tmp,vector<int>& nums,vector<vector<int>> &ans){
        if(index==nums.size()){
            ans.push_back(tmp);
            return;
        }
        //take
        tmp.push_back(nums[index]);
        solve(index+1,tmp,nums,ans);

        //not take
        tmp.pop_back();
        solve(index+1,tmp,nums,ans);        

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int>tmp;
        solve(0,tmp,nums,ans);
        return ans;
    }
};