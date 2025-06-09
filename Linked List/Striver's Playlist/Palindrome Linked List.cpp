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
    ListNode* left;
    bool solve(ListNode* right){
        if(right == NULL){
            return true;
        }
        bool isPal = solve(right->next);
        if(!isPal) return false;

        bool check = (left->val == right->val);
        left = left->next;
        return check;
    }

    bool isPalindrome(ListNode* head) {
        left = head;
        return solve(head);
    }
};
