class Solution {
public:    
    int minDistance(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        // Tabulation and space optimisation
        vector<int> prev(m + 1,0),cur(m + 1,0);

        for (int j = 0; j <= m; j++)
            prev[j] = j; // i==0 return j

        for (int i = 1; i <= n; i++) {
            cur[0]=i;
            for (int j = 1; j <= m; j++) {
                if (s1[i - 1] == s2[j - 1]) {
                    cur[j] = prev[j-1];
                } else{
                    // try insert, delete, and replace
                    cur[j] = 1 + min(prev[j],min(cur[j-1], prev[j-1]));
                }
            }
            prev=cur;
        }
        return prev[m];
    }
};