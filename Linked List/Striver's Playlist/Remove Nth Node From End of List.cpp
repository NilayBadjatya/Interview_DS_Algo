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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* prev = head;
        ListNode* temp = head;
        int k = n;
        while(k--){
            temp = temp->next;
        }
        if(temp == NULL){
            ListNode* temp = head->next;
            delete(head); // To avoid Memory leakage
            return temp;
        }
        while(temp != NULL && temp->next != NULL){
            prev = prev->next;
            temp = temp->next;
        }
        ListNode* t = prev->next;
        prev->next = prev->next->next;
        delete(t);
        return head;
    }
};
