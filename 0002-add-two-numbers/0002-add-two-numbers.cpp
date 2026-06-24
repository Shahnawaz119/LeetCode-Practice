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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1==NULL && l2==NULL){
            return NULL;
        }
        if(l1==NULL && l2!=NULL){
            return l2;
        }
        if(l1!=NULL && l2==NULL){
            return l1;
        }
        ListNode* dummay=new ListNode(0);
        ListNode* curr=dummay;
        ListNode* p=l1;
        ListNode* q=l2;
        int carry=0;
        while(p!=NULL || q!=NULL){
            int sum=0;
            if(p!=NULL){
                sum+=p->val;
                p=p->next;
            }
            if(q!=NULL){
                sum+=q->val;
                q=q->next;
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
            curr=curr->next;
        }
        return dummay->next;

    }
};