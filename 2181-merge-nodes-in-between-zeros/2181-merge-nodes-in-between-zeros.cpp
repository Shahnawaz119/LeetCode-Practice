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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* temp=head;
        ListNode* newHead=new ListNode(0);
        ListNode* Head_new=newHead;
        while(temp){
            int sum=0;
            if(temp->val!=0){
                while(temp!=NULL && temp->val!=0){
                    sum+=temp->val;
                    temp=temp->next;
                }
                ListNode* newNode=new ListNode(sum);
                newHead->next=newNode;
                newHead=newHead->next;
            }else{
                temp=temp->next;
            }
        }
        return Head_new->next;
    }
};