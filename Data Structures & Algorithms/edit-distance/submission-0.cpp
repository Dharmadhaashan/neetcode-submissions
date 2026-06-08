class Solution {
public:
    int func(string s,string p,int i,int j){
        if(i<0){
            return j+1;
        }
        if(j<0){
            return i+1;
        }
        if(s[i]==p[j]){
            return func(s,p,i-1,j-1);
        }
        int ans1 = 1 + func(s,p,i,j-1);
        int ans2 = 1 + func(s,p,i-1,j);
        int ans3 = 1 + func(s,p,i-1,j-1);
        return min({ans1,ans2,ans3});
    }
    int minDistance(string word1, string word2) {
        int ans = func(word1,word2,word1.size()-1,word2.size()-1);
        return ans;
    }
};
