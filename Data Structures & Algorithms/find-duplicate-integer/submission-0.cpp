class Solution {
public:
    int findDuplicate(vector<int>& n) {
        int slow = n[0];
        int fast = n[0];
        do{
            slow = n[slow];
            fast = n[n[fast]];
        }while(slow != fast);
        fast=n[0];
        while(slow != fast){
            slow = n[slow];
            fast = n[fast];
        }
        return slow;
    }
};
