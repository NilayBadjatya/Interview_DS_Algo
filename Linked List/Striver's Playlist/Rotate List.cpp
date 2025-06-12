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

    vector<int> convertArray(ListNode* head){
        ListNode* p = head;
        vector<int> arr;

        while(p != NULL){
            arr.push_back(p->val);
            p = p->next;
        }

        return arr;
    }

    ListNode* rotateRight(ListNode* head, int k) {

        if(k == 0 || head == NULL || head->next == NULL){
            return head;
        }

        vector<int> nums = convertArray(head);
        int n = nums.size();

        k = k % n;
        while(k--){
            vector<int> temp(n);
            for(int i = 0; i < n; i++){
                int idx = (i+1) % n;
                temp[idx] = nums[i];
            }

            nums = temp;
        }

        ListNode* newHead = new ListNode(-1);
        ListNode* p = newHead;
        int i = 0;
        while(p != NULL && i < n){
            ListNode* temp = new ListNode(nums[i]);
            p->next = temp;
            p = temp;
            i++;
        }

        return newHead->next;
    }
};
