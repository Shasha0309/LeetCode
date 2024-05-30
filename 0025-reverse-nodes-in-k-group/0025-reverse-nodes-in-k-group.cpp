/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* tofindkthnode(ListNode* head,int k){
        k -= 1;
         while(k>0 && head!=NULL){
              head=head->next;
              k--;
         }
         return head;
    }
    ListNode* reverse(ListNode* head){
        ListNode* temp = head;
       ListNode* prev = NULL;
       ListNode* front;
       while(temp!=NULL){
        front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
       } 
       return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* kthNode;
        ListNode* nextNode;
        ListNode* preNode = NULL;
        while(temp!=NULL){
        kthNode = tofindkthnode(temp,k);

        if(kthNode==NULL){ 
                  if (preNode) preNode->next = temp; 
            break;
            }
        nextNode = kthNode->next;
        kthNode->next=NULL;
        reverse(temp);
        if(temp==head){ 
            head=kthNode; 
            }
            else{
                preNode->next = kthNode;
            }
            preNode = temp;
            temp = nextNode;
        }
        return head;
    }
};