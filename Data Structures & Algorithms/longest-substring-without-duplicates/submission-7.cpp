class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()==0){
            return 0;
        }
        if(s.size()==1){
            return 1;
        }
        int maxi = 1;
        for(int i=0;i<s.size();i++){
            set<char>st;
            for(int j=i;j<s.size();j++){
                if(st.find(s[j])!=st.end()){
                    break;
                }
                else{
                    st.insert(s[j]);
                }
            }
            maxi = max(maxi,int(st.size()));
        }
        return maxi;
    }
};
