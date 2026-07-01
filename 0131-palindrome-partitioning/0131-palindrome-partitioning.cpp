class Solution {
public:
    bool isPallindrome(string &s) {
        int l=0,r=s.size()-1;
        while (l < r) {
            if (s[l] != s[r])
                return false;

            l++;
            r--;
        }

        return true;
    }
    void solve(int index, vector<string>& partition,
               vector<vector<string>>& ans, string s) {
        if (index == s.size()) {
            ans.push_back(partition);
            return;
        }

        for (int i = index; i < s.size(); i++) {
            string part = s.substr(index, i - index + 1);
            if (isPallindrome(part)) {
                partition.push_back(part);
                solve(i + 1, partition, ans, s);
                partition.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> partition;
        solve(0, partition, ans, s);
        return ans;
    }
};