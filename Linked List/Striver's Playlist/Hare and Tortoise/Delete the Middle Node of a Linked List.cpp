class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(head->next == NULL){
            return NULL;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* t = head;
        while(fast && fast->next){
            t = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        t->next = slow->next;
        return head;
    }
};
