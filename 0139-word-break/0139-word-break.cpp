class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> dp(s.size() + 1, false);
        dp[s.size()] = true;
        for (int i = s.size() - 1; i >= 0; i--) {
            for (auto& word : wordDict) {
                if (s.substr(i, word.size()) == word) {
                    if (dp[i + word.size()]) {

                        dp[i] = true;
                        break;
                    }
                }
            }
        }
        return dp[0];
    }
};