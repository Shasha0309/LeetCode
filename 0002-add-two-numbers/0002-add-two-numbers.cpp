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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp = new ListNode();
        ListNode* dummy = temp;
        ListNode* head1 = l1;
        ListNode* head2 = l2;
        int carry = 0;

        while(head1!=NULL || head2!=NULL){
            int sum = carry;
            if(head1) sum += head1->val;
            if(head2) sum += head2->val;
            ListNode* res = new ListNode(sum%10);
            dummy->next = res;
            dummy=res;
            carry = sum/10;
            if(head1) head1 = head1->next;
            if(head2) head2 = head2->next;
        }
        if(carry){
            ListNode* node = new ListNode(carry);
            dummy->next = node;
         } 
         return temp->next;
    }
};