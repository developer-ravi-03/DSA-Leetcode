class Solution {
public:
    int helper(int i,int j,string &s1,string &s2,vector<vector<int>>&dp){
        //exhausted
        if(i==0) return j;
        if(j==0) return i;

        //check dp for result
        if(dp[i][j]!=-1)return dp[i][j];

        //if matching 
        if(s1[i-1]==s2[j-1]){
            return dp[i][j]=0+helper(i-1,j-1,s1,s2,dp);
        }
        //try insert, delete, and replace
        return dp[i][j]=1+min(helper(i,j-1,s1,s2,dp),min(helper(i-1,j,s1,s2,dp),helper(i-1,j-1,s1,s2,dp)));
    }
    int minDistance(string s1, string s2) {
        int n=s1.size();
        int m=s2.size();
        //memoization
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return helper(n,m,s1,s2,dp);
    }
};