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
    ListNode * reverse(ListNode *head){
        ListNode * prev = NULL;
        while(head != NULL){
            ListNode *next = head ->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        head = reverse(head);
        ListNode * current = head;
        if(n==1){
            head = head->next;
        }
        else{
            while(n!=2){
                current = current->next;
                n--;
            }
            ListNode * nextnode = current->next->next;
            ListNode * delnode = current->next;
            delnode->next = NULL;
            current->next = nextnode;
        }
        head = reverse(head);
        return head;
    }
};
