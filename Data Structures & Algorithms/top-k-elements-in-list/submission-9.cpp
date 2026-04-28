class Solution {
public:
    vector<int> topKFrequent(vector<int>& n, int k) {
        unordered_map<int,int>mpp;
        for(int i=0;i<n.size();i++){
            mpp[n[i]]++;
        }
        vector<pair<int,int>>a;
        for(const auto& i:mpp){
            a.push_back({i.second,i.first});
        }
        sort(a.rbegin(),a.rend());
        vector<int>b;
        for(int i=0;i<k;i++){
            b.push_back(a[i].second);
        }
        return b;
    }
};
