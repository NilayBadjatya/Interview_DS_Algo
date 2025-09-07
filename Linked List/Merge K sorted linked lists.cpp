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
    Node* mergeKLists(vector<Node*>& arr) {
        // code here
        vector<int> val;
        for(int i = 0; i < arr.size(); i++){
            Node* head = arr[i];
            while(head != NULL){
                val.push_back(head->data);
                head = head->next;
            }
        }
        sort(val.begin(), val.end());
        Node* newHead = new Node(-1);
        Node* p = newHead;
        for(int i = 0; i < val.size(); i++){
            Node* temp = new Node(val[i]);
            p->next = temp;
            p = p->next;
        }
        return newHead->next;
    }
};
