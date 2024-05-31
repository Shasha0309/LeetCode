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
    ListNode* findLastNode(ListNode* head,int k){
        int cnt = 1;
        while(head!=NULL){
            if(cnt==k) return head;
            cnt++;
            head=head->next;
        }
        return head;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || k==0) return head;
        
        ListNode* temp = head;
        int len = 1;
        while(temp->next!=NULL){
            len++;
            temp=temp->next;
        }
        int res = k%len;
        if(res==0) return head;
        k = k%len;
        temp->next = head;
        ListNode* lastNode = findLastNode(head,len-k);
        
        head=lastNode->next;
        lastNode->next = NULL;
        return head;
    }
};