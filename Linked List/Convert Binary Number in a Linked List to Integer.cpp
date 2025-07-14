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
    int getDecimalValue(ListNode* head) {
        string s = "";
        ListNode* p = head;
        while(p != NULL){
            s += to_string(p->val);
            p = p->next;
        }
        reverse(s.begin(), s.end());
        int num = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '0') continue;
            num += (1 << i);
        }
        return num;
    }
};
