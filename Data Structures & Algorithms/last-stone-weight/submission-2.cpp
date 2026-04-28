class Solution {
public:
    int lastStoneWeight(vector<int>& s) {
        priority_queue<int>pq;
        for(int i:s){
            pq.push(i);
        }
        while(pq.size()>1){
            int f = pq.top();
            pq.pop();
            int s = pq.top();
            pq.pop();
            int e = f-s;
            if(e==0){
                if(pq.size()==0){
                    return 0;
                }
                continue;
            }
            pq.push(e);
        }
        return pq.top();
    }
};
