class Solution {
public:
    int longestConsecutive(vector<int>& n) {
        if (n.size()==0){
            return 0;
        }
        if(n.size()==1){
            return 1;
        }
        sort(n.begin(),n.end());
        int max=0;
        int sum=0;
        for(int i=0;i<n.size()-1;i++){
            if(n[i]==n[i+1]){
                continue;
            }
            if(n[i]+1==n[i+1]){
                sum++;
            }
            else{
                if(sum>=max){
                    max=sum;
                    sum=0;
                }
            }
        }
        if(max>sum){
            return max+1;
        }
        else{
            return sum+1;
        }
    }
};
