class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& p, int k) {
        priority_queue<
    pair<int, vector<int>>,
    vector<pair<int, vector<int>>>,
    greater<pair<int, vector<int>>>
> pq;
        for(vector<int> i:p){
            int x = i[0];
            int y = i[1];
            int d = x*x + y*y;
            pq.push({d,{x,y}});
        }
        vector<vector<int>> ans;
        for(int i=0;i<k;i++){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};
