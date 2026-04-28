class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummy; 
        ListNode* travel = &dummy;
        ListNode* current1 = list1;
        ListNode* current2 = list2;

        while (current1 != NULL && current2 != NULL) {
            if (current1->val >= current2->val) {
                travel->next = new ListNode(current2->val);
                current2 = current2->next;
            } else {
                travel->next = new ListNode(current1->val);
                current1 = current1->next;
            }
            travel = travel->next;
        }
        while (current1 != NULL) {
            travel->next = new ListNode(current1->val);
            current1 = current1->next;
            travel = travel->next;
        }
        while (current2 != NULL) {
            travel->next = new ListNode(current2->val);
            current2 = current2->next;
            travel = travel->next;
        }

        return dummy.next;
    }
};
