// Brute Force
class Solution {
public:

    int findLength(ListNode* head){
        ListNode* p = head;
        int len = 0;
        while(p != NULL){
            p = p->next;
            len++;
        }
        return len;
    }

    ListNode* middleNode(ListNode* head) {
        int n = findLength(head);
        int middleIdx = n / 2;

        ListNode* p = head;
        int idx = 0;
        while(idx < middleIdx){
            p = p->next;
            idx++;
        }

        return p;
    }
};


// Optimal(Hare and Tortoise)

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;

        while(fast != NULL && fast->next != NULL){
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
};
