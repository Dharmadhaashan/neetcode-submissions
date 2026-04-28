class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans ; 
        deque<int> dq ; 
        for ( int i = 0 ; i < nums.size() ; i ++ ) {
            int val = nums[i] ; 
            while ( !dq.empty() && val > dq.back() ) {
                dq.pop_back() ; 
            }
            dq.push_back(val) ; 
            if ( i >= k && dq.front() == nums[ i - k ] ) dq.pop_front() ; 
            if ( i >= k - 1 ) ans.push_back(dq.front()) ; 
        }
        return ans ; 
    }
};