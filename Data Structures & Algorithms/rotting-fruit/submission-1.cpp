class Solution {
public:
    int orangesRotting(vector<vector<int>>& g) {
        int n = g.size();
        int m = g[0].size();

        queue<pair<int,int>> q;
        vector<vector<int>> vis(n, vector<int>(m, 0));

        int cnt = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(g[i][j] == 2) {
                    q.push({i, j});
                    vis[i][j] = 1;
                }

                if(g[i][j] == 1) {
                    cnt++;
                }
            }
        }

        vector<int> dr{-1, 1, 0, 0};
        vector<int> dc{0, 0, -1, 1};

        int step = 0;
        int cn = 0;

        while(!q.empty()) {
            int size = q.size();
            bool changed = false;

            for(int i = 0; i < size; i++) {
                int r = q.front().first;
                int c = q.front().second;
                q.pop();

                for(int j = 0; j < 4; j++) {
                    int nr = r + dr[j];
                    int nc = c + dc[j];

                    if(nr < 0 || nr >= n || nc < 0 || nc >= m)
                        continue;

                    if(g[nr][nc] == 1 && !vis[nr][nc]) {
                        cn++;
                        changed = true;

                        q.push({nr, nc});
                        vis[nr][nc] = 1;
                    }
                }
            }

            if(changed)
                step++;
        }

        if(cnt != cn)
            return -1;

        return step;
    }
};