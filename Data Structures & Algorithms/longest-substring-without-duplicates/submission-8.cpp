class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0;
        int r = 0;
        int ans = 0;
        string temp = "";

        while (r < s.size()) {
            if (temp.find(s[r]) == string::npos) {
                temp += s[r];
                ans = max(ans, (int)temp.size());
                r++;
            } else {
                temp.erase(0, 1); 
                l++;
            }
        }

        return ans;
    }
};