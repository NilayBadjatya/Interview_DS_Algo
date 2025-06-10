class Solution {
  public:
  
    Node* reverseLL(Node* Head){
        Node* p = NULL;
        Node* q = Head;
        while(q != NULL){
            Node* nxt = q->next;
            q->next = p;
            p = q;
            q = nxt;
        }
        return p;
    }
  
    Node* addOne(Node* head) {
        Node* revHead = reverseLL(head);
        int val = revHead->data, carry = 0;
        if(val + 1 > 9){
            carry = 1;
            revHead->data = 0;
        }else{
            revHead->data = val+1;
        }
        
        Node* p = revHead->next;
        Node *last = revHead;
        while(p != NULL && carry == 1){
            int val = p->data;
            if(val + 1 > 9){
                if(p->next == NULL){
                    last = p;
                }
                p->data = 0;
            }else{
                p->data = val+1;
                carry = 0;
            }
            p = p->next;
        }
        
        if(carry){
            Node* newNode = new Node(1);
            last->next = newNode;
        }
        
        Node* ModifiedHead = reverseLL(revHead);
        return ModifiedHead;
    }
};
