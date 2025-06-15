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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head = new ListNode(-1);
        ListNode* temp = head;
        ListNode* fir = list1;
        ListNode* sec = list2;
        while(fir!=NULL && sec!=NULL){
            if(fir->val <= sec->val){
               temp->next = fir;
               fir=fir->next;
            }
            else{
                temp->next = sec;
                sec=sec->next;
            }
            temp=temp->next;
        }
        if(fir) temp->next=fir;
        if(sec) temp->next=sec;
        return head->next;
    }
};