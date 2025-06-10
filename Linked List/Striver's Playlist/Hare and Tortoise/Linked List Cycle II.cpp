class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;

        int cycle = 0;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){
                cycle = 1;
                break;
            }
        }
        if(!cycle) return NULL;

        slow = head;
        while(slow != fast){
            slow = slow->next;
            fast = fast->next;
        }

        return slow;
    }
};
