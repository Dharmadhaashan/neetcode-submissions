class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()==0){
            return 0;
        }
        if(s.size()==1){
            return 1;
        }
        int ans=0;
        for(int i=0;i<s.size();i++){
            set<char>st;
            for(int j=i;j<s.size();j++){
                char key=s[j];
                if(st.find(key) != st.end()){
                    break;
                }
                else{
                    st.insert(key);
                }
            }
            int res=st.size();
            ans=max(ans,res);
        }
        return ans;
    }
};
