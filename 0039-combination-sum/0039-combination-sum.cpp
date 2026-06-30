class Solution {
public:
    void solve(int index,vector<int>& tmp,vector<int>& candidates,int target,vector<vector<int>>&ans,int sum){
        if(sum > target)
            return;
        if(index==candidates.size()) return;
        if(sum==target){
            ans.push_back(tmp);
            return;
        }

        tmp.push_back(candidates[index]);
        solve(index,tmp,candidates,target,ans,sum+candidates[index]);


        tmp.pop_back();
        solve(index+1,tmp,candidates,target,ans,sum);

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> tmp;
        int sum=0;
        solve(0,tmp,candidates,target,ans,sum);
        return ans;
    }
};