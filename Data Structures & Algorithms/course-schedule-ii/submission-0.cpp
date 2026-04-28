class Solution {
public:
    vector<int> findOrder(int V, vector<vector<int>>& edges) {
        vector<vector<int>>adj (V);
        for(auto i :edges){
            adj[i[1]].push_back(i[0]);
        }

        vector<int> indegree(V,0);
        for(int i = 0;i<V;i++){
            for(auto j:adj[i]){
                indegree[j]++;
            }
        }
        vector<int>topo;
        queue<int>q;
        for(int i=0;i<V;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }

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
            return topo;
        }
        return {};
    }
};
