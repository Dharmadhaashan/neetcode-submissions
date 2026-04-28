class Solution {
public:
    vector<int> productExceptSelf(vector<int>& n) {
        vector<int>res;
        int pro=1;
        int pro1=1;
        int zero=0;
        for(int i=0;i<n.size();i++){
            pro=pro*n[i];
            if(n[i]!=0){
                pro1=pro1*n[i];
            }
            if(n[i]==0){
                zero++;
            }
        }
        if(zero>1){
            return vector<int>(n.size(), 0);
        }
        for(int j=0;j<n.size();j++){
            if(n[j]!=0){
                int x=pro/n[j];
                res.push_back(x);
            }
            else{
                res.push_back(pro1);
            }
            
        }
        return res;
        
    }
};
