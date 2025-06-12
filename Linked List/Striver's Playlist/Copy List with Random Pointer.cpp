/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:

    int findIdx(Node* head, Node* target){
        int i = 0;
        Node* p = head;
        while(p != target){
            i++;
            p = p->next;
        }
        return i;
    }

    Node* copyRandomList(Node* head) {
        Node* p = head;
        unordered_map<int, int> toRandom;
        int i = 0;
        while(p != NULL){
            if(p->random == NULL){
                toRandom[i] = -1;
            }else{
                int idx = findIdx(head, p->random);
                toRandom[i] = idx;
            }
            i++;
            p = p->next;
        }

        Node* newHead = new Node(-1);
        p = head;
        Node* q = newHead;
        while(p != NULL){
            Node* newNode = new Node(p->val);
            q->next = newNode;
            q = newNode;
            p = p->next;
        }

        i = 0;
        p = newHead->next;
        while(p != NULL){
            int idx = toRandom[i++];
            if(idx == -1){
                p->random = NULL;
                p = p->next;
                continue;
            }
            Node* q = newHead->next;
            int j = 0;
            while(j != idx && q != NULL){
                q = q->next;
                j++;
            }
            p->random = q;
            p = p->next;
        }

        return newHead->next;
    }
};
