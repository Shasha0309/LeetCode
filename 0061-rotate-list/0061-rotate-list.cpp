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
    ListNode* sol(ListNode* head,int k){
        int cnt = 1;
        while(head!=NULL){
            if(cnt==k) return head;
            cnt++;
            head=head->next;
        }
        return head;
    }
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || k==0) return head;
        int n = 1;
        ListNode* temp = head;
        while(temp->next!=NULL){
            temp=temp->next;
            n++;
        }
        k=k%n;
        if(k==0) return head;
        temp->next = head;
       
        ListNode* lis = sol(head,n-k);
        head = lis->next;
        lis->next= NULL;
        
        return head;
    }
};