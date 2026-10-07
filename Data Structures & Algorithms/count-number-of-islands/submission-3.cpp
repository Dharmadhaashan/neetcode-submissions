class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        vector<vector<int>>vis(grid.size(),vector<int>(grid[0].size(),0));
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]=='1' && !vis[i][j]){
                    ans++;
                    queue<vector<int>>q;
                    q.push({i,j});
                    while(!q.empty()){
                        vector<int>t = q.front();
                        q.pop();
                        int row = t[0];
                        int col = t[1];
                        vis[row][col]=1;
                        if(row-1 >=0 && !vis[row-1][col] && grid[row-1][col]=='1'){
                            vis[row-1][col]=1;
                            q.push({row-1,col});
                        }
                        if(row+1<grid.size() && !vis[row+1][col] && grid[row+1][col]=='1'){
                            vis[row+1][col]=1;
                            q.push({row+1,col});
                        }
                        if(col-1>=0 && !vis[row][col-1] && grid[row][col-1]=='1'){
                            vis[row][col-1]=1;
                            q.push({row,col-1});
                        }
                        if(col+1<grid[0].size() && !vis[row][col+1] && grid[row][col+1]=='1'){
                            vis[row][col+1]=1;
                            q.push({row,col+1});
                        }
                    }
                }
            }
        }
        return ans;
    }
};
