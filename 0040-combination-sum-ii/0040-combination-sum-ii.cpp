class Solution {
public:
    void solve(int index, vector<int>& tmp, vector<int>& candidates, int target,
               vector<vector<int>>& ans, int sum) {
        if (sum == target) {
            ans.push_back(tmp);
            return;
        }
        if (sum > target)
            return;

        if (index == candidates.size())
            return;

        for (int i = index; i < candidates.size(); i++) {
            if (i > index && candidates[i] == candidates[i - 1]) {
                continue;
            }

            if (sum + candidates[i] > target)
                break;
            tmp.push_back(candidates[i]);
            solve(i + 1, tmp, candidates, target, ans, sum + candidates[i]);
            tmp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> tmp;
        int sum = 0;
        solve(0, tmp, candidates, target, ans, sum);
        return ans;
    }
};