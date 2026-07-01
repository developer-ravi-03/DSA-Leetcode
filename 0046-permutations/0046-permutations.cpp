class Solution {
public:
    void solve(vector<int>& nums,vector<int> &tmp,vector<vector<int>> &ans,vector<bool> &visited){
        if(nums.size()==tmp.size()){
            ans.push_back(tmp);
            return;
        }

        for(int i=0;i<nums.size();i++){
            if(visited[i]) continue;

            //choose
            visited[i]=true;
            tmp.push_back(nums[i]);

            solve(nums,tmp,ans,visited);

            //backtrack unchoose
            tmp.pop_back();
            visited[i]=false;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> tmp;
        vector<bool> visited(nums.size(),false);
        solve(nums,tmp,ans,visited);
        return ans;
        
    }
};