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
// Insert copy nodes in between
// Connect random pointers
// Connect next pointer
void copyNodes(Node* head){
        Node* temp = head;
        while(temp!=NULL){
          Node* newNode = new Node(temp->val);
          newNode->next = temp->next;
          temp->next = newNode;
          temp=temp->next->next;
        }
    }
    void randomPointer(Node* head){
        Node* temp = head;
        while(temp!=NULL){
            if(temp->random){
            temp->next->random = temp->random->next;
            }
            else{
            temp->next->random = nullptr;
            }
            temp = temp->next->next;
        }
    }
    Node* connectNext(Node* head){
        Node* dummyNode = new Node(-1);
        Node* res = dummyNode;
        Node* temp = head;
        while(temp!=NULL){
        res->next = temp->next;
        res = res->next;
        temp->next = temp->next->next;
        temp=temp->next;
        }
        return dummyNode->next;
    }
class Solution {
public:
    Node* copyRandomList(Node* head) {
        copyNodes(head);
        randomPointer(head);
        return connectNext(head);
    }
};