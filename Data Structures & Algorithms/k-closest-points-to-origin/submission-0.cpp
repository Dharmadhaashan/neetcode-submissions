class Solution {
public:
    priority_queue<int,vector<int>,greater<int>>minheap;

    vector<vector<int>> kClosest(vector<vector<int>>& p, int k) {
        int row = p.size();
        int col = 2;
        vector<pair<float,int>>a;
        for(int i=0;i<row;i++){
            int x = p[i][0];
            int y = p[i][1];
            float d = sqrt((x*x) + (y*y));
            a.push_back({d,i});
        }
        sort(a.begin(),a.end());
        vector<vector<int>>res;
        for(int i=0;i<k;i++){
            vector<int>b;
            b.push_back(p[a[i].second][0]);
            b.push_back(p[a[i].second][1]);
            res.push_back(b);
        }
        return res;
    }
};
