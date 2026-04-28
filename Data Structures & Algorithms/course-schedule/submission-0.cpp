class Solution {
public:
    bool canFinish(int V, vector<vector<int>>& edges) {
        vector<int> adj[V];
        for(auto i: edges){
            adj[i[0]].push_back(i[1]);
        }
        
        int indegree[V] = {0};
        for(int i=0;i<V;i++){
            for(auto i:adj[i]){
                indegree[i]++;
            }
        }
        
        queue<int>q;
        for(int i=0;i<V;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        
        vector<int>topo;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            topo.push_back(node);
            
            for(auto i:adj[node]){
                indegree[i]--;
                if(indegree[i]==0){
                    q.push(i);
                }
            }
        }
        
        if(topo.size()==V){
            return true;
        }
        return false;
    }
};
