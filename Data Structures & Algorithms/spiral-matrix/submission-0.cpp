class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();

        int left = 0, right = col - 1;
        int top = 0, bottom = row - 1;

        vector<int> res;
        
        while (res.size() < row * col) {
            for (int i = left; i <= right && res.size() < row * col; i++) {
                res.push_back(matrix[top][i]);
            }
            top++;

            for (int i = top; i <= bottom && res.size() < row * col; i++) {
                res.push_back(matrix[i][right]);
            }
            right--;

            for (int i = right; i >= left && res.size() < row * col; i--) {
                res.push_back(matrix[bottom][i]);
            }
            bottom--;

            for (int i = bottom; i >= top && res.size() < row * col; i--) {
                res.push_back(matrix[i][left]);
            }
            left++;
        }

        return res;
    }
};
