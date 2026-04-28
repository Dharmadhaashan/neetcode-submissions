class Solution {
public:
    bool isHappy(int n) {
        int sum=n;
        vector<int>a;
        while(sum!=1){
            int s=0;
            while(n!=0){
                int rem=n%10;
                s=s+(rem*rem);
                n=n/10;
            }
            if(s==1){
                return true;
            }
            else{
                int c=count(a.begin(),a.end(),s);
                if(c>0){
                    return false;
                }
                else{
                    a.push_back(s);
                }
                sum=s;
                n=s;
            }
        }
        return true;
    }
};
