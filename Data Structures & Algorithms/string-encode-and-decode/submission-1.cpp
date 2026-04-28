class Solution {
public:

    string encode(vector<string>& st) {
        string s;
        for(int i=0;i<st.size();i++){
            for(int j=0;j<st[i].size();j++){
                s.push_back(st[i][j]);
            }
            s.push_back('/');
        }
        return s;
    }

    vector<string> decode(string s) {
        vector<string>a;
        string st;
        int in=0;
        for(char i:s){
            if(i !='/'){
                st.push_back(s[in]);
            }
            in++;
            if(i=='/'){
                a.push_back(st);
                st.clear();
            }
        }
        return a;
    }
};
