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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* first = head;
        ListNode* sec = head;
        for(int i=0;i<n;i++) first=first->next;
         if(first==NULL) return head->next;
        while(first->next!=NULL){
        
                first=first->next;
                sec=sec->next;
            
        }
       
    ListNode* temp = sec->next;
       sec->next = temp->next;
       delete temp;
    
        return head; 
    }
};