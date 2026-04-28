class Solution {
public:
    int func(int i,int j,int m,int n){
        if(i==0 && j==0) return 1;
        if(i<0 || j<0) return 0;
        return func(i-1,j,m,n)+func(i,j-1,m,n);
    }
    int uniquePaths(int m, int n) {
        return func(m-1,n-1,m,n);
    }
};
