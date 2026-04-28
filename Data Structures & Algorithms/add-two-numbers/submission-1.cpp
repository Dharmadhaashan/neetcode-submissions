/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int n1=0;
        ListNode *current1 = l1;
        int flag1=0;
        int i=0;
        while(current1 != NULL){
            n1 = n1 + (current1->val * pow(10,i));
            i++;
            /*
            if(flag1==0){
                n1=current1->val;
                flag1=1;
            }
            else{
                n1 = n1+ (current1->val*10);
            }*/
            current1 = current1->next;
        }
        int n2 =0;
        ListNode * current2 = l2;
        int flag2=0;
        int j=0;
        while(current2 != NULL){
            n2 = n2 + (current2->val * pow(10,j));
            j++;
            /*
            if(flag2 == 0){
                n2=current2->val;
                flag2=1;
            }
            else{
                n2 = n2 + (current2->val*10);
            }*/
            current2 = current2->next;
        }
        int res = n1+n2;
        if (res == 0) {
            return new ListNode(0);
        }
        ListNode * dummy = new ListNode(-1);
        ListNode * travel=dummy;
        while(res != 0){
            int rem = res%10;
            ListNode * current = new ListNode(rem);
            travel->next = current;
            travel = travel->next;
            res = res/10;
        }
        return dummy->next;
    }
};
