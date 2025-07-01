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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==NULL && list2==NULL){
            return NULL;
        }
        if(list1!=NULL && list2==NULL){
            return list1;
        }
        if(list1==NULL && list2!=NULL){
            return list2;
        }
        ListNode* temp=new ListNode(100);
        ListNode* temp1=temp;
        while(list1!=NULL && list2!=NULL){
            if(list1->val<=list2->val){
                temp1->next=list1;
                list1=list1->next;
                temp1=temp1->next;
            }else{
                temp1->next=list2;
                list2=list2->next;
                temp1=temp1->next;
            }
        }
        if(list1!=NULL){
            temp1->next=list1;
        }else{
            temp1->next=list2;
        }
        return temp->next;
    }
};