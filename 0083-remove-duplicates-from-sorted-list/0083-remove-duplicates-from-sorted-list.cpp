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
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* a=head;
        ListNode* b=head->next;
        while(b!=NULL){
            if(a->val==b->val){
                ListNode* del=b;
                b=b->next;
                a->next=b;
                delete del;
            }else{
                a=b;
                b=b->next;
            }
        }
        return head;
    }
};