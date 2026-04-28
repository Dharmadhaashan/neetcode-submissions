class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        for(auto e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        int ans =0;
        vector<bool>vis(n,false);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                ans++;
                dfs(i,adj,vis);
            }
        }
        return ans;
    }
    void dfs(int node,vector<vector<int>>adj,vector<bool>& vis){
        vis[node]=true;
        for(int i:adj[node]){
            if(!vis[i]){
                dfs(i,adj,vis);
            }
        }
        return;
    }
};
