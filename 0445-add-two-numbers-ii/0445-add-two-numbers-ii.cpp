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
    ListNode* reverse(ListNode* head){
        ListNode* prev=NULL;
        ListNode* next=NULL;
        ListNode* curr=head;
        while(curr){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1==NULL && l2==NULL){
            return NULL;
        }
        
        l1=reverse(l1);
        l2=reverse(l2);
        ListNode* dummy=new ListNode(0);
        ListNode* curr=dummy;
        int carry=0;
        while(l1!=NULL || l2!=NULL){
            int sum=0;
            if(l1!=NULL){
                sum+=l1->val;
                l1=l1->next;
            }
            if(l2!=NULL){
                sum+=l2->val;
                l2=l2->next;
            }
            sum+=carry;
            ListNode* newNode=new ListNode(sum%10);
            curr->next=newNode;
            curr=curr->next;
            carry=sum/10;
        }
        if(carry>0){
            ListNode* newNode=new ListNode(carry);
            curr->next=newNode;
        }
        ListNode* ans=reverse(dummy->next);
        return ans;
    }
};