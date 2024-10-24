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
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode* ptr = head;
        vector<int> ans;
        while(ptr){
            ans.push_back(ptr->val);
            ptr=ptr->next;
        }
        sort(ans.begin(),ans.end());
        ptr=head;
        int i=0;
        while(ptr){
            ptr->val=ans[i++];
            ptr=ptr->next;
        }
        return head;
    }
};