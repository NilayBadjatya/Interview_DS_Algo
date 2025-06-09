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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        string s1 = "", s2 = "";
        ListNode* p = l1;
        while (p != NULL) {
            s1 += to_string(p->val);
            p = p->next;
        }
        p = l2;
        while (p != NULL) {
            s2 += to_string(p->val);
            p = p->next;
        }
        // reverse(s1.begin(), s1.end());
        // reverse(s2.begin(), s2.end());
        cout << s1 << " " << s2;
        ListNode* head = new ListNode();
        p = head;
        int carry = 0, n = min(s1.size(), s2.size()), i = 0;
        for (i = 0; i < n; i++) {
            int x = (s1[i] - '0'), y = (s2[i] - '0');
            int res = x + y + carry;
            if (res <= 9) {
                carry = 0;
            } else {
                carry = 1;
            }
            string t = to_string(res);
            int data = 0;
            if (t.size() == 2) {
                data = (t[1] - '0');
            } else {
                data = (t[0] - '0');
            }
            ListNode* temp = new ListNode(data);
            p->next = temp;
            p = p->next;
        }
        if (i < s1.size()) {
            while (i < s1.size()) {
                int x = (s1[i] - '0');
                int res = x + carry;
                if (res <= 9) {
                    carry = 0;
                } else {
                    carry = 1;
                }
                string t = to_string(res);
                int data = 0;
                if (t.size() == 2) {
                    data = (t[1] - '0');
                } else {
                    data = (t[0] - '0');
                }
                ListNode* temp = new ListNode(data);
                p->next = temp;
                p = p->next;
                i++;
            }
        } else if (i < s2.size()) {
            while (i < s2.size()) {
                int x = (s2[i] - '0');
                int res = x + carry;
                if (res <= 9) {
                    carry = 0;
                } else {
                    carry = 1;
                }
                string t = to_string(res);
                int data = 0;
                if (t.size() == 2) {
                    data = (t[1] - '0');
                } else {
                    data = (t[0] - '0');
                }
                ListNode* temp = new ListNode(data);
                p->next = temp;
                p = p->next;
                i++;
            }
        }
        if(carry == 1){
            ListNode* temp = new ListNode(1);
            p->next = temp;
            p = p->next;
        }
        return head->next;
    }
};
