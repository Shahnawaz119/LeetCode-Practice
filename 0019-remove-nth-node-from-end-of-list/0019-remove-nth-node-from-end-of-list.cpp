/**
 * Definition for singly-linked list.
 * struct ListListNode {
 *     int val;
 *     ListListNode *next;
 *     ListListNode() : val(0), next(nullptr) {}
 *     ListListNode(int x) : val(x), next(nullptr) {}
 *     ListListNode(int x, ListListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void DeleteListNode(ListNode* &head,int n){
        if(head->next==NULL && n==1){
            ListNode* temp=head;
            head=NULL;
            delete temp;
            return;
        }
        ListNode* temp=head;
        int size=0;
        while(temp!=NULL){
            temp=temp->next;
            size++;
        }
        if(size==n){
            ListNode* temp=head;
            head=head->next;
            delete temp;
            return;
        }
        ListNode* prevListNode=head;
        for(int i=1; i<(size-n); i++){
            prevListNode=prevListNode->next;
        }
        ListNode* toDel=prevListNode->next;
        prevListNode->next=prevListNode->next->next;
        delete toDel;
        return;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        DeleteListNode(head,n);
        return head;
    }
};