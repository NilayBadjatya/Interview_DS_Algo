// Iterative Approach
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* p = NULL;
        ListNode* q = head;

        while(q != NULL){
            ListNode* nxt = q->next;
            q->next = p;
            p = q;
            q = nxt;
        }

        return p;
    }
};

// Recursive Approach
class Solution {
public:

    ListNode* recursiveReverse(ListNode* head){
        if(head == NULL || head->next == NULL){
            return head;
        }

        ListNode* newHead = recursiveReverse(head->next);
        ListNode* front = head->next;
        front->next = head;
        head->next = NULL;
        return newHead;
    }

    ListNode* reverseList(ListNode* head) {
        return recursiveReverse(head);
    }
};
