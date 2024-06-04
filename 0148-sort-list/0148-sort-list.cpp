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

    ListNode* findMiddle(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head->next;
            while(fast!=NULL && fast->next!=NULL){
                slow = slow->next;
                fast=fast->next->next;
            }
        return slow;
    }

    ListNode* merge(ListNode* firstHalf, ListNode* secondHalf){
        ListNode* dummyNode = new ListNode(-1);
        ListNode* temp = dummyNode;
        while(firstHalf!=NULL && secondHalf!=NULL){
            if(firstHalf->val<secondHalf->val){
               temp->next = firstHalf;
               temp = firstHalf;
               firstHalf = firstHalf->next;
            }
            else{
                temp->next = secondHalf;
               temp = secondHalf;
               secondHalf = secondHalf->next;
            }
            if(firstHalf) temp->next = firstHalf;
            else temp->next = secondHalf;
        }
      return dummyNode->next;
    }
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
    ListNode* middle = findMiddle(head);
    ListNode* secondHalf = middle->next;
    middle->next = nullptr;
    ListNode* firstHalf = head;
    

    firstHalf = sortList(firstHalf);
    secondHalf = sortList(secondHalf);
    return merge(firstHalf,secondHalf);
    }
};