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
    ListNode* reverseKGroup(ListNode* head, int k) {
        vector<int> nums;
        ListNode* p = head;
        while(p != NULL){
            nums.push_back(p->val);
            p = p->next;
        }

        int n = nums.size();
        int swaps = n / k;

        int i = 0, j = k-1;
        while(swaps--){
            reverse(nums.begin() + i, nums.begin() + j + 1);
            i = j+1;
            j += k;
        }

        ListNode* newHead = new ListNode(-1);
        p = newHead;
        i = 0;
        while(i < n){
            ListNode* nextNode = new ListNode(nums[i++]);
            p->next = nextNode;
            p = nextNode;
        }

        return newHead->next;
    }
};
