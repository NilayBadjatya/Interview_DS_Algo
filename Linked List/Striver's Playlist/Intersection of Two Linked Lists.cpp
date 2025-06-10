class Solution {
public:

    int findLength(ListNode* head){
        int len = 0;
        ListNode* p = head;
        while(p != NULL){
            p = p->next;
            len++;
        }
        return len;
    }

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int m = findLength(headA);
        int n = findLength(headB);

        ListNode* a = headA;
        ListNode* b = headB;
        if(m >= n){
            int diff = m - n;
            while(diff--){
                a = a->next;
            }
        }else if(n >= m){
            int diff = n - m;
            while(diff--){
                b = b->next;
            }
        }

        while(a != NULL && b != NULL && a != b){
            a = a->next;
            b = b->next;
        }

        if(a == NULL || b == NULL) return NULL;
        return a;
    }
};
