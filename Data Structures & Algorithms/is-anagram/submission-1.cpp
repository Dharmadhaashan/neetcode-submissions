class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,char>mp1;
        for(char i:s){
            mp1[i]++;
        }
        for(char i:t){
            if(mp1.find(i)==mp1.end()){
                return false;
            }
            mp1[i]--;
        }
        for(auto i:mp1){
            if(i.second>0){
                return false;
            }
        }
        return true;
    }
};
