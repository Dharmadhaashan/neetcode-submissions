class Solution {
public:
    priority_queue<int> maxheap;

    int lastStoneWeight(vector<int>& stones) {
        for(int i:stones){
            maxheap.push(i);
        }
        while(maxheap.size()>1){
            int last = maxheap.top();
            maxheap.pop();
            int before = maxheap.top();
            maxheap.pop();
            int e = last-before;
            if(e !=0){
                maxheap.push(e);
            }
        }
        if(maxheap.empty()){
            return 0;
        }
        return maxheap.top();
    }
};
