/*
class Node {
  public:
    int data;
    Node *next;
    Node *prev;
    Node(int val) {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

*/
class Solution {
  public:
    Node *reverse(Node *head) {
        // code here
        if(head->next == NULL){
            return head;
        }
        Node* p = head;
        Node* q = head->next;
        while(p != NULL){
            Node* temp = p->prev;
            p->prev = q;
            p->next = temp;
            if(q == NULL) break;
            p = q;
            q = q->next;
        }
        
        return p;
    }
};
