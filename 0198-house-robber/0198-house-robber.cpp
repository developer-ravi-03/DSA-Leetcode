class Solution {
public:

    int solve(int i,int free,int n, vector<int>& nums,vector<vector<int>> &dp){
        if(i==n) return 0;

        if(dp[i][free]!=-1) return dp[i][free];

        if(free==0){
            return dp[i][free]=solve(i+1,1,n,nums,dp);
        }

        int a1=nums[i]+solve(i+1,0,n,nums,dp);
        int a2=solve(i+1,1,n,nums,dp);
        return dp[i][free]=max(a1,a2);
    }

    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n);
        for(int i=0;i<n;i++){
            vector<int>t(2,-1);
            dp[i]=t;
        }
        return solve(0,1,n,nums,dp);
    }
};