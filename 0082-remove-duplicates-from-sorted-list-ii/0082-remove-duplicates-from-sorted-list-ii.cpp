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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* curr=head;
        ListNode* prev=NULL;
        while(curr){
            if(curr->next!=NULL && curr->val==curr->next->val){
                int val=curr->next;
                while(curr!=NULL curr->val==val){
                    curr=curr->next;
                }
                if(prev!=NULL){
                    head=curr;
                }else{
                    prev->next=curr;
                }
            }else{
                prev=curr;
                curr=curr->next;
            }
        }
        return head;
    }
};