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
  
    Node* split(Node* head){
        Node* slow = head;
        Node* fast = head;
        
        while(fast && fast->next){
            fast = fast->next->next;
            if(fast != nullptr)
                slow = slow->next;
        }
        
        Node* temp = slow->next;
        slow->next = nullptr;
        return temp;
    }
    
    Node* merge(Node* first, Node* second){
        if(!first) return second;
        if(!second) return first;
        if(first->data < second->data){
            first->next = merge(first->next, second);
            return first;
        }else{
            second->next = merge(first, second->next);
            return second;
        }
    }
  
    Node* mergeSort(Node* head) {
        // code here
        if(!head || !head->next) return head;
        
        Node* second = split(head);
        
        head = mergeSort(head);
        second = mergeSort(second);
        
        return merge(head, second);
    }
};
