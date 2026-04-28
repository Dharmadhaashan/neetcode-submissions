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
    ListNode * findmedian (ListNode * head){
        ListNode * slow=head;
        ListNode * fast = head;
        while(fast!=NULL && fast->next !=NULL){
            slow = slow->next;
            fast=fast->next->next;
        }
        return slow;
    }

    ListNode * reverselist(ListNode * head){
        ListNode * prev= NULL;
        while(head!=NULL){
            ListNode *next = head->next;
            head->next = prev;
            prev=head;
            head=next;
        }
        return prev;
    }

    ListNode * mergell(ListNode * l1,ListNode *l2){
        ListNode * dummy = new ListNode(-1);
        ListNode * current = dummy;
        while(l1 !=NULL && l2 != NULL){
            current->next = l1;
            l1 = l1->next;
            current = current ->next;
            current->next = l2;
            l2 = l2->next;
            current = current ->next;
        }
        if(l1 != NULL){
            current->next = l1;
        }
        if(l2 != NULL){
            current->next = l2;
        }
        return dummy->next;
    }

    void reorderList(ListNode* head) {
        if(head->next == NULL || head->next->next == NULL){
            return ;
        }
        ListNode * middle = findmedian(head);
        ListNode * l2 = middle->next;
        middle->next = NULL;
        l2 = reverselist(l2);
        head = mergell(head,l2);
    }
};
