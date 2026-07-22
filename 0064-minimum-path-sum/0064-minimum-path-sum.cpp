class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        vector<int> prev(m, 0);

        for (int i = 0; i < n; i++) {

            vector<int> cur(m, 0);

            for (int j = 0; j < m; j++) {

                if (i == 0 && j == 0) {
                    cur[j] = grid[i][j];
                }
                else {

                    int up = 1e9;
                    int left = 1e9;

                    if (i > 0)
                        up = grid[i][j] + prev[j];

                    if (j > 0)
                        left = grid[i][j] + cur[j - 1];

                    cur[j] = min(up, left);
                }
            }

            prev = cur;
        }

        return prev[m - 1];
    }
};