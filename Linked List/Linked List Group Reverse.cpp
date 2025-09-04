/*
class Node {
  public:
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution {
  public:
    Node *reverseKGroup(Node *head, int k) {
        // code here
        if(k == 1){
            return head;
        }
        vector<int> a;
        Node* p = head;
        while(p != NULL){
            a.push_back(p->data);
            p = p->next;
        }
        int last = 0, n = a.size();
        for(int i = k-1; i < n; i += k){
            reverse(a.begin() + last, a.begin() + i + 1);
            last = i+1;
        }
        if(last < n){
            reverse(a.begin() + last, a.end());
        }
        Node* newHead = new Node(-1);
        p = newHead;
        for(int i = 0; i < n; i++){
            Node* newNode = new Node(a[i]);
            p->next = newNode;
            p = p->next;
        }
        return newHead->next;
    }
};
