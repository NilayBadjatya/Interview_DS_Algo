/*  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};*/

// Watch Striver's video for revision of the approach.

class Solution {
  public:
    Node* segregate(Node* head) {
        // code here
        Node* dummyZero = new Node(-1);
        Node* dummyOne = new Node(-1);
        Node* dummyTwo = new Node(-1);
        
        Node* zero = dummyZero;
        Node* one = dummyOne;
        Node* two = dummyTwo;
        
        Node* p = head;
        while(p != NULL){
            if(p->data == 0){
                zero->next = p;
                zero = zero->next;
            }else if(p->data == 1){
                one->next = p;
                one = one->next;
            }else{
                two->next = p;
                two = two->next;
            }
            p = p->next;
        }
        
        if(dummyOne->next == NULL){
            zero->next = dummyTwo->next;
        }else{
            zero->next = dummyOne->next;
        }
        
        if(dummyOne->next != NULL){
            one->next = dummyTwo->next;
        }
        two->next = NULL;
        return dummyZero->next;
    }
};
