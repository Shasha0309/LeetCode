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
        ListNode* ans = new ListNode();
        ListNode* ansoo = ans;
        int car = 0;
        int sum = 0;
        while(l1!=NULL || l2!=NULL){
            sum = car;
            if(l1) sum+=l1->val;
            if(l2) sum+=l2->val;
            ListNode* newnode = new ListNode(sum%10);
            car = sum/10;
            ansoo->next = newnode;
            ansoo = newnode;
            if(l1) l1=l1->next;
            if(l2) l2=l2->next;
        }
        
         if(car){
           ListNode* nes = new ListNode(1);
           ansoo->next = nes;
        } 
        return ans->next;
    }
};