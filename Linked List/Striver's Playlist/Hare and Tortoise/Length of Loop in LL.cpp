/*
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution {
  public:
    // Function to find the length of a loop in the linked list.
    int countNodesinLoop(Node *head) {
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
        
        if(!cycle) return 0;
        
        slow = head;
        while(slow != fast){
            slow = slow->next;
            fast = fast->next;
        }
        
        Node* temp = slow->next;
        int len = 1;
        
        while(temp != slow){
            temp = temp->next;
            len++;
        }
        
        return len;
        
    }
};
