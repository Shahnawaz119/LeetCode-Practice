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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        if(k==0){
            return head;
        }
        int len=1;
        ListNode* temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
            len++;
        }
        if(k>len){
            k=k%len;
        }
        if(k==0 || k==len){
            return head;
        }
        ListNode* curr=head;
        for(int i=1; i<(len-k); i++){
            curr=curr->next;
        }
        ListNode* newHead=curr->next;
        curr->next=NULL;
        ListNode* newCurr=newHead;
        while(newCurr->next!=NULL){
            newCurr=newCurr->next;
        }
        newCurr->next=head;
        head=newHead;
        return newHead;
    }

};