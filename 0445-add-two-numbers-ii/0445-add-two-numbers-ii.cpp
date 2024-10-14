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
    ListNode* reverse(ListNode* head){
        if(head==NULL || head->next==NULL) return head;
        ListNode* newNode = reverse(head->next);
        ListNode* curr = head->next;
        curr->next = head;
        head->next = NULL;
        return newNode;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp1 = reverse(l1);
        ListNode* temp2 = reverse(l2);
        ListNode* head = new ListNode();
        ListNode* dummy = head;
        int carry = 0;
        while(temp1!=NULL || temp2!=NULL){
            int sum = carry;
            if(temp1) sum += temp1->val;
            if(temp2) sum += temp2->val;
            ListNode* newone = new ListNode(sum%10);
            carry = sum/10;
            dummy->next = newone;
            dummy = dummy->next;
            if(temp1) temp1=temp1->next;
            if(temp2) temp2=temp2->next;
        }
        if(carry){
            ListNode* res = new ListNode(carry);
            dummy->next = res;
        }

        return reverse(head->next);
    }
};