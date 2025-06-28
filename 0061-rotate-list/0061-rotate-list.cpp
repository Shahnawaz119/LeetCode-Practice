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
        ListNode* temp1=head;
        for(int i=1; i<(len-k); i++){
            temp1=temp1->next;
        }
        ListNode* newHead=temp1->next;
        temp1->next=NULL;
        ListNode* nhead=newHead;
        while(nhead->next!=NULL){
            nhead=nhead->next;
        }
        nhead->next=head;
        head=newHead;
        return head;
        
    }
};