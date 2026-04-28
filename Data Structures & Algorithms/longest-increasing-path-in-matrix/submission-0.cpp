class Solution {
public:
    int maxi = 0;
    void travel(vector<vector<int>>& m, int i, int j, int cnt){
        if(i<0 || j<0 || i>=m.size() || j>=m[0].size()){
            return ;
        }
        if(i-1>=0 && m[i-1][j]>m[i][j]){
            maxi = max(maxi,cnt+1);
            travel(m,i-1,j,cnt+1);
        }
        if(j+1<m[0].size() && m[i][j+1]>m[i][j]){
            maxi = max(maxi,cnt+1);
            travel(m,i,j+1,cnt+1);
        }
        if(i+1<m.size() && m[i+1][j]>m[i][j]){
            maxi = max(maxi,cnt+1);
            travel(m,i+1,j,cnt+1);
        }
        if(j-1>=0 && m[i][j-1]>m[i][j]){
            maxi = max(maxi,cnt+1);
            travel(m,i,j-1,cnt+1);
        }
    }
    int longestIncreasingPath(vector<vector<int>>& m) {
        int n = m.size();
        int p = m[0].size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < p; j++) {
                travel(m, i, j, 0);
            }
        }

        return maxi + 1;
    }
};
