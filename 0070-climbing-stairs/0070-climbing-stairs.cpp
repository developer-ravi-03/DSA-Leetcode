class Solution {
public:
    unordered_map<int,int>dp;
    int climbStairs(int n) {
        if (n==1 || n==2) return n;
        if(dp.find(n)!=dp.end()) return dp[n];

        int ans=climbStairs(n-1)+climbStairs(n-2);
        dp[n]=ans;

        return ans;
    }
};