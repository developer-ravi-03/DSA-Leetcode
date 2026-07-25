class Solution {
public:
    bool helper(int i, string &s, vector<string>& wordDict,vector<int>&dp) {
        if (i == s.size())
            return true;
        
        if(dp[i]!=-1) return dp[i];

        for (auto& word : wordDict) {
            if (s.substr(i, word.size()) == word) {
                if (helper(i + word.size(), s, wordDict,dp))
                    return dp[i]=true;
            }
        }
        
        return dp[i]=false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
       vector<int>dp(s.size()+1,-1);
        return helper(0, s, wordDict,dp);
    }
};