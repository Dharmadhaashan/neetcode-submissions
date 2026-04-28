class Solution {
public:
    vector<string> res;
    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0) {
            return {};
        }
        unordered_map<char, string> mp;
        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";
        backtrack(0, "", digits, mp);
        return res;
    }
    void backtrack(int start, string curr, string digits,
                   unordered_map<char, string> mp) {
        if (curr.size() == digits.size()) {
            res.push_back(curr);
            return;
        }
        for (char c : mp[digits[start]]) {
            curr.push_back(c);
            backtrack(start + 1, curr, digits, mp);
            curr.pop_back();
        }
    }
};