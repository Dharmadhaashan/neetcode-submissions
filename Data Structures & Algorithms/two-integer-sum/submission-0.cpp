class Solution {
public:
    vector<int> twoSum(vector<int>& n, int t) {
        vector<int>a;
        for(int i=0;i<n.size();i++){
            for(int j=0;j<n.size();j++){
                if(n[i]+n[j]==t && i !=j){
                    a.push_back(i);
                    a.push_back(j);
                    return a;
                }
            }
        }
    }
};
