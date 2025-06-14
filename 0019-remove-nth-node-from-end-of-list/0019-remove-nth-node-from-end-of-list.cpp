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
        ListNode* second = head;
        int i=0;
        while(i<n){
           second = second->next;
           i++;
        }
        if(second==NULL) return head->next;
        while(second->next!=NULL){
            second = second->next;
            first = first->next;
        }
       ListNode* delnode = first->next;
       first->next= first->next->next;
       delete (delnode);
        return head;

       
    }
};