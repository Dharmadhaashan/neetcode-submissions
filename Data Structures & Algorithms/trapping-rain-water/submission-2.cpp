class Solution {
public:
    int trap(vector<int>& h) {
        int n = h.size();
        int l = 0;
        int ans = 0;

        while (l < n) {
            int r = l + 1;

            while (r < n && h[r] < h[l]) {
                r++;
            }

            if (r == n) {      
                l++;
                continue;
            }

            int mini = h[l];

            for (int i = l + 1; i < r; i++) {
                ans += mini - h[i];
            }

            l = r;
        }

        return ans;
    }
};