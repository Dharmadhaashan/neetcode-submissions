class Solution {
public:
    int n, p;
    vector<vector<int>> dp;   

    int travel(vector<vector<int>>& m, int i, int j) {
        if (dp[i][j] != -1) return dp[i][j];

        int best = 1; 

        if (i - 1 >= 0 && m[i - 1][j] > m[i][j]) {
            best = max(best, 1 + travel(m, i - 1, j));
        }
        if (j + 1 < p && m[i][j + 1] > m[i][j]) {
            best = max(best, 1 + travel(m, i, j + 1));
        }
        if (i + 1 < n && m[i + 1][j] > m[i][j]) {
            best = max(best, 1 + travel(m, i + 1, j));
        }
        if (j - 1 >= 0 && m[i][j - 1] > m[i][j]) {
            best = max(best, 1 + travel(m, i, j - 1));
        }

        return dp[i][j] = best;
    }

    int longestIncreasingPath(vector<vector<int>>& m) {
        n = m.size();
        p = m[0].size();
        dp.assign(n, vector<int>(p, -1));

        int maxi = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < p; j++) {
                maxi = max(maxi, travel(m, i, j));
            }
        }
        return maxi;
    }
};
