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
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL){
            return head;
        }
        ListNode* p = head;
        ListNode* q = head->next;
        ListNode* lastOdd = head;
        ListNode* firstEven = q;
        while(p != NULL && q != NULL){
            p->next = q->next;
            if(p !=NULL && p->next == NULL){
                lastOdd = p;
            }
            p = p->next;
            if(p != NULL && p->next == NULL){
                lastOdd = p;
            }
            if(p != NULL){
                q->next = p->next;
            }
            q = q->next;
        }
        lastOdd->next = firstEven;
        return head;
    }
};
