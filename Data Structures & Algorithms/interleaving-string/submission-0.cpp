class Solution {
public:
    bool func(string a, string b, string c,int i,int j,int k){
        if (i < 0 && j < 0 && k < 0)
            return true;

        if (k < 0)
            return false;

        if (i < 0)
            return b[j] == c[k] && func(a, b, c, i, j - 1, k - 1);

        if (j < 0)
            return a[i] == c[k] && func(a, b, c, i - 1, j, k - 1);

        bool takeA = false, takeB = false;

        if (a[i] == c[k])
            takeA = func(a, b, c, i - 1, j, k - 1);

        if (b[j] == c[k])
            takeB = func(a, b, c, i, j - 1, k - 1);

        return takeA || takeB;
    }
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size()+s2.size()!=s3.size()){
            return false;
        }
        return func(s1,s2,s3,s1.size()-1,s2.size()-1,s3.size()-1);
    }
};
