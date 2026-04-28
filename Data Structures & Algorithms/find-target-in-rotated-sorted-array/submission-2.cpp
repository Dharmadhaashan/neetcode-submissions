class Solution {
public:
    int search(vector<int>& n, int target) {
        if(n.size()==1 && n[0]==target){
            return 0;
        }
        if (n.size()==1 && n[0]!=target){
            return -1;
        }
        int low=0;
        int high = n.size()-1;
        while(low<=high){
            int mid = (low+high)/2;
            if(n[mid]==target){
                return mid;
            }
            if(n[low]<=n[mid]){
                if(n[low]<=target && target<=n[mid]){
                    high = mid-1;
                }
                else{
                    low = mid+1;
                }
            }
            else{
                if(n[mid]<=target && n[high]>=target){
                    low = mid+1;
                }
                else{
                    high = mid-1;
                }
            }
        }
        return -1;
    }
};
