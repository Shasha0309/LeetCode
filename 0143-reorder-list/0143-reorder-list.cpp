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
    ListNode* reverse(ListNode* head){
        if(head==NULL || head->next==NULL) return head;
        ListNode* newnode = reverse(head->next);
        ListNode* temp = head->next;
        temp->next = head;
        head->next=NULL;
        return newnode;
    }
public:
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* first = head;
        fast=fast->next;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* revnode = reverse(slow->next);
        slow->next=NULL;
        while(revnode){
           ListNode* temp1 = first->next;
           ListNode* temp2 = revnode->next;
           first->next = revnode;
           revnode->next = temp1;
           first = temp1;
           revnode = temp2;
        }
    }
};