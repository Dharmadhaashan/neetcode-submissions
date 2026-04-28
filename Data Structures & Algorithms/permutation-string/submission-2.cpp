class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size()>s2.size())
            return false;
        unordered_map<char,int>mp1;
        for(char i:s1){
            mp1[i]++;
        }
        for(int i=0;i<=s2.size()-s1.size();i++){
            unordered_map<char,int>mp2;
            for(int j=i;j<i+s1.size();j++){
                mp2[s2[j]]++;
            }
            if (mp1 == mp2)
                return true;
        }
        return false;
    }
};
