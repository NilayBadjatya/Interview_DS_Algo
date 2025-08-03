/*
class Node {
  public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};
*/
class Solution {
  public:
    void removeLoop(Node* head) {
        // code here
        Node* slow = head;
        Node* fast = head;
        int cycle = 0;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){
                cycle = 1;
                break;
            }
        }
        if(!cycle) return;
        slow = head;
        while(slow != fast){
            fast = fast->next;
            slow = slow->next;
        }
        while(fast->next != slow){
            fast = fast->next;
        }
        fast->next = NULL;
    }
};
