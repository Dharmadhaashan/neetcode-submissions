class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& g) {
        vector<vector<int>>vis(g.size(),vector<int>(g[0].size(),0));
        vector<vector<int>>mat = g;
        vector<pair<int,int>>v;
        queue<pair<pair<int,int>,int>>q;
        for(int i=0;i<g.size();i++){
            for(int j=0;j<g[0].size();j++){
                if(g[i][j]==0){
                    q.push({{i,j},0});
                }
            }
        }
        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int t = q.front().second;
            q.pop();
            if(!vis[row][col]){
                vis[row][col] = 1;
                if(row-1>=0 && g[row-1][col] == 2147483647){
                    g[row-1][col]=t+1;
                    q.push({{row-1,col},t+1});
                }
                if(row+1<g.size() && g[row+1][col] == 2147483647){
                    g[row+1][col]=t+1;
                    q.push({{row+1,col},t+1});
                }
                if(col-1>=0 && g[row][col-1] == 2147483647){
                    g[row][col-1]=t+1;
                    q.push({{row,col-1},t+1});
                }
                if(col+1<g[0].size() && g[row][col+1] == 2147483647){
                    g[row][col+1]=t+1;
                    q.push({{row,col+1},t+1});
                }
            }
        }
    }
};
