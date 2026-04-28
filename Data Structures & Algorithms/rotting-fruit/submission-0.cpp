class Solution {
public:
    int orangesRotting(vector<vector<int>>& g) {
        int time = 0;
        queue<pair<pair<int,int>,int>> q;
        vector<pair<int,int>> v;
        int n = g.size(), m = g[0].size();

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(g[i][j]==1){
                    v.push_back({i,j});
                }
                if(g[i][j]==2){
                    q.push({{i,j},0});
                }
            }
        }

        vector<vector<int>> vis(n,vector<int>(m,0));

        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int t = q.front().second;
            time = t;
            q.pop();

            if(!vis[row][col]){
                vis[row][col]=1;

                // up
                if(row-1 >=0 && g[row-1][col]==1){
                    g[row-1][col] = 2; // mark rotten
                    q.push({{row-1,col},t+1});
                }
                // down
                if(row+1<n && g[row+1][col]==1){
                    g[row+1][col] = 2;
                    q.push({{row+1,col},t+1});
                }
                // left
                if(col-1>=0 && g[row][col-1]==1){
                    g[row][col-1] = 2;
                    q.push({{row,col-1},t+1});
                }
                // right
                if(col+1<m && g[row][col+1]==1){
                    g[row][col+1] = 2;
                    q.push({{row,col+1},t+1});
                }
            }
        }

        for(auto i:v){
            if(vis[i.first][i.second]!=1){
                return -1;
            }
        }
        return time;
    }
};
