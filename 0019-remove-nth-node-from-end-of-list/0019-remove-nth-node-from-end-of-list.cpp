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
       /* ListNode* first = head;
        ListNode* second = head;
        int i=0;
        while(i<n){
           second = second->next;
           i++;
        }
        while(second!=NULL && second->next!=NULL){
            second = second->next;
            first = first->next;
        }
       if(first->next->next!=NULL) first->next= first->next->next;
       else first->next=NULL;
        return head;*/

       if(head==NULL) return NULL;
        int len = 0;
        ListNode* fir = head;
        while(fir!=NULL){
            fir = fir->next;
            len++;
        }
        if(n==len){
            ListNode* newhead = head->next;
            delete (head);
             return newhead; 
        }
        fir=head;
        int res = len-n;
         while(fir!=NULL){
            res--;
            if(res==0) break;
            fir=fir->next;
         }
         ListNode* delnode = fir->next;
         fir->next=fir->next->next;
         delete (delnode);
         return head;
    }
};