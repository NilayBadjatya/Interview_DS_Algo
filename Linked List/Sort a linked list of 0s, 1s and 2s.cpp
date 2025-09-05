/* Node is defined as
  class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/
class Solution {
  public:
    Node* segregate(Node* head) {
        // code here
        int zero = 0, one = 0, two = 0;
        Node* p = head;
        while(p != NULL){
            if(p->data == 0){
                zero++;
            }else if(p->data == 1){
                one++;
            }else{
                two++;
            }
            p = p->next;
        }
        
        p = head;
        while(zero--){
            p->data = 0;
            p = p->next;
        }
        while(one--){
            p->data = 1;
            p = p->next;
        }
        while(two--){
            p->data = 2;
            p = p->next;
        }
        return head;
    }
};
