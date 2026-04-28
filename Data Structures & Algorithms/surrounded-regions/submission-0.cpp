class Solution {
public:
    void solve(vector<vector<char>>& b) {
        vector<vector<int>> vis(b.size(), vector<int>(b[0].size(), 0));

        for(int i = 0; i < b.size(); i++){
            func(b, i, 0, vis);
            func(b, i, b[0].size()-1, vis);
        }
        for(int j = 0; j < b[0].size(); j++){
            func(b, 0, j, vis);
            func(b, b.size()-1, j, vis);
        }

        for(int i = 0; i < b.size(); i++){
            for(int j = 0; j < b[0].size(); j++){
                if(!vis[i][j]){
                    b[i][j] = 'X'; 
                }
            }
        }
    }

    void func(vector<vector<char>>& b, int i, int j, vector<vector<int>>& vis){
        if(i < 0 || j < 0 || i >= b.size() || j >= b[0].size()) return;
        if(b[i][j] == 'X' || vis[i][j]) return;

        vis[i][j] = 1;
        func(b, i-1, j, vis);
        func(b, i+1, j, vis);
        func(b, i, j-1, vis);
        func(b, i, j+1, vis);
    }
};
