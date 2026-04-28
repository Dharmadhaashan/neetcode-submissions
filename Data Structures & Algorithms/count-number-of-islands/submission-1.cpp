class Solution {
public:
    void bfs(int row,int col,vector<vector<char>>& g,vector<vector<int>>& vis){
        int n = g.size();
        int m = g[0].size();
        queue<pair<int,int>>q;
        vis[row][col]=1;
        q.push({row,col});
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            int delrow[4]={-1,0,1,0};
            int delcol[4]={0,1,0,-1};
            for(int i=0;i<4;i++){
                int nrow = r + delrow[i];
                int ncol = c + delcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m 
                   && g[nrow][ncol]=='1' && !vis[nrow][ncol]){
                    vis[nrow][ncol]=1;
                    q.push({nrow,ncol});
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& g) {
        int row = g.size();
        int col = g[0].size();
        vector<vector<int>>vis(row,vector<int>(col,0));
        int ans=0;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(vis[i][j] == 0 && g[i][j]=='1'){
                    ans++;
                    bfs(i,j,g,vis);
                }
            }
        }
        return ans;
    }
};
