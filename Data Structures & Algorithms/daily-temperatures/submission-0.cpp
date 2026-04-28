class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        int n=temp.size();
        vector<int>res(n,0);
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                if(temp[j]>temp[i]){
                    res[i]=(j-i);
                    break;
                }
            }
        }
        return res;
    }
};
