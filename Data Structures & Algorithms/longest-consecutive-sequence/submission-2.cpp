class Solution {
public:
    int longestConsecutive(vector<int>& n) {
        unordered_set<int>mp(n.begin(),n.end());
        int maxi = 0;
        for(auto i:mp){
            if(mp.find(i-1)==mp.end()){
                int length = 1;
                while(mp.find(i+length)!=mp.end()){
                    length++;
                }
                maxi = max(maxi,length);
            }
        }
        return maxi;
    }
};
