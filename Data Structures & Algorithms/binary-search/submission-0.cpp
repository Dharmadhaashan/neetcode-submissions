class Solution {
public:
    int search(vector<int>& n, int t) {
        if (n.size() == 0) {
            return -1;
        } else if (n.size() == 1 && n[0] == t) {
            return 0;
        } else if (n.size() > 1) {
            int low = 0;
            int high = n.size() - 1;
            while (low <= high) {
                int mid = low + (high - low) / 2;

                if (n[mid] == t)
                    return mid;

                if (n[mid] < t)
                    low = mid + 1;
                else
                    high = mid - 1;
            }
        }
        return -1;
    }
};
