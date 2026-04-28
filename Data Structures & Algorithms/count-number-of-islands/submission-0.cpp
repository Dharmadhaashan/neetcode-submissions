class Solution {
private:
    void bfs(int row,int col,vector<vector<int>> &vis,vector<vector<char>>& g){
        vis[row][col]=1;
        queue<pair<int,int>>q;
        q.push({row,col});
        int n=g.size();
        int m = g[0].size();

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            int delRow[4] = {-1, 0, 1, 0};
            int delCol[4] = {0, 1, 0, -1};
            for(int i = 0; i < 4; i++){
                int nrow = row + delRow[i];
                int ncol = col + delCol[i];
                
                if(nrow >=0 && nrow < n && ncol>=0 && ncol < m 
                && g[nrow][ncol]=='1' && !vis[nrow][ncol]){
                    vis[nrow][ncol] = 1;
                    q.push({nrow,ncol});
                }
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& g) {
        int n = g.size();
        int m = g[0].size();
        vector<vector<int>>vis(n, vector<int>(m,0));
        int count=0;
        for(int row=0;row<n;row++){
            for(int col =0;col<m;col++){
                if(!vis[row][col] && g[row][col] == '1'){
                    count++;
                    bfs(row,col,vis,g);
                }
            }
        }
        return count;
    }
};