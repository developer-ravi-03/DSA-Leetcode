class Solution {
public:
    int helper(int i,int j,int n,int m,string &t1,string &t2,vector<vector<int>>&dp){
        if(i==n || j==m) return 0;

        if(dp[i][j]!=-1) return dp[i][j];

        if(t1[i]==t2[j]) return dp[i][j]=1+helper(i+1,j+1,n,m,t1,t2,dp);
        int skip1=helper(i+1,j,n,m,t1,t2,dp);
        int skip2=helper(i,j+1,n,m,t1,t2,dp);
        return dp[i][j]=max(skip1,skip2);
    }

    int longestCommonSubsequence(string t1, string t2) {
        int n=t1.size();
        int m=t2.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return helper(0,0,n,m,t1,t2,dp);
    }
};