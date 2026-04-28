#include <vector>
#include <queue>
#include <algorithm> // for max
using namespace std;

class Solution {
    int maxi = 0;

private:
    void bfs(int row, int col, vector<vector<int>>& vis, vector<vector<int>>& g) {
        int n = g.size();
        int m = g[0].size();
        vis[row][col] = 1;
        queue<pair<int, int>> q;
        q.push({row, col});
        int count = 0;
        
        int delrow[4] = {-1, 0, 1, 0};
        int delcol[4] = {0, 1, 0, -1};

        while (!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            count++;

            for (int i = 0; i < 4; i++) {
                int nrow = r + delrow[i];
                int ncol = c + delcol[i];
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m 
                    && g[nrow][ncol] == 1 && !vis[nrow][ncol]) {
                    vis[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }
        }
        
        maxi = max(maxi, count);
    }

public:
    int maxAreaOfIsland(vector<vector<int>>& g) {
        int n = g.size();
        int m = g[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));

        for (int row = 0; row < n; row++) {
            for (int col = 0; col < m; col++) {
                if (!vis[row][col] && g[row][col] == 1) {
                    bfs(row, col, vis, g);
                }
            }
        }
        return maxi;
    }
};
