class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& e) {
        int n=e.size();
        vector<int>ds(n+1);
        for(int i=0;i<=n;i++){
            ds[i]=i;
        }
        for(vector<int>v:e){
            int ed1=v[0];
            int ed2=v[1];
            
            int p1 = findparent(ed1,ds);
            int p2 = findparent(ed2,ds);

            if(p1==p2) return v;
            else{
                ds[p2]=p1;
            }
        }
        return {};
    }
    int findparent(int ele,vector<int>& ds){
        if(ds[ele]==ele) return ele;
        return findparent(ds[ele],ds);
    }
};
