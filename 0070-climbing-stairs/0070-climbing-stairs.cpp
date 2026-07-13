class Solution {
public:
    unordered_map<int,int>dp;
    int helper(int i,int n){
        if(i==n) return 1;

        if(i>n) return 0;

        if(dp.find(i)!=dp.end()){
            return dp[i];
        }
        int a1=helper(i+1,n);
        int a2=helper(i+2,n);
        int ans=a1+a2;
        dp[i]=ans;
        return ans;
    }
    int climbStairs(int n) {
        return helper(0,n);
    }
};