class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        vector<int>ans(t.size(),0);
        stack<pair<int,int>>st;
        for(int i=0;i<t.size();i++){
            while (!st.empty() && st.top().first < t[i]) {
                int idx = st.top().second;
                st.pop();
                ans[idx] = i - idx;
            }

            st.push({t[i], i});
        }
        return ans;
    }
};
