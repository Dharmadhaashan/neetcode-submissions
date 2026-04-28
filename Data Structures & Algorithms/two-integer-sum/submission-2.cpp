class Solution {
public:
    vector<int> twoSum(vector<int>& n, int target) {
        unordered_map<int,int> mp;  
        for (int i = 0; i < n.size(); i++) {
            int t = target - n[i];
            if (mp.find(t) != mp.end()) {
                return {mp[t], i};
            }
            mp[n[i]] = i;
        }
        return {};
    }
};
