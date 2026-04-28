class Solution {
public:
    double myPow(double x, int n) {
        int n1=n;
        double r = x;
        double r1 = r;
        if(n==0){
            return 1.00000;
        }

        if (n < 0) {
            x = 1 / x;
            n = -n;
        }

        for (int i = 1; i < n; i++) {
            r = r * r1;
        }
        if(n1 <0){
            return 1/r;
        }
        return r;
    }
};
