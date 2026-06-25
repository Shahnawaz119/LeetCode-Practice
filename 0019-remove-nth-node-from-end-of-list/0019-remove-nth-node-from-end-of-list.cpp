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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL){
            return NULL;
        }
        if(head->next==NULL && n==1){
            ListNode* delNode=head;
            head=NULL;
            delete delNode;
            return head;
        }
        int size=0;
        ListNode* temp=head;
        while(temp){
            size++;
            temp=temp->next;
        }
        if(n==size){
            ListNode* delNode=head;
            head=head->next;
            delete delNode;
            return head;
        }
        ListNode* prev=head;
        for(int i=1; i<(size-n); i++){
            prev=prev->next;
        }
        ListNode* delNode=prev->next;
        prev->next=prev->next->next;
        delete delNode;
        return head;

    }
};