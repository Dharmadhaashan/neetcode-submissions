class Solution {
public:
    bool dfs(int node,int parent,vector<vector<int>>adj,vector<bool>&vis){
        if(vis[node]){
            return false;
        }
        vis[node]=true;
        for(int i:adj[node]){
            if(i!=parent && !dfs(i,node,adj,vis)){
                return false;
            }
        }
        return true;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        vector<bool>vis(n,false);
        for(auto edge:edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        if(!(dfs(0,-1,adj,vis))){
            return false;
        }
        for(bool v:vis){
            if(!v){
                return false;
            }
        }
        return true;
    }
    
};
