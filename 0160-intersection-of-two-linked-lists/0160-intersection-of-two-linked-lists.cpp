/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA==NULL && headB==NULL){
            return NULL;
        }
        int len1=0,len2=0;
        ListNode* tempA=headA;
        ListNode* tempB=headB;
        while(tempA){
            len1++;
            tempA=tempA->next;
        }
        while(tempB){
            len2++;
            tempB=tempB->next;
        }
        tempA=headA;
        tempB=headB;
        if(len1>len2){
            int diff=len1-len2;
            for(int i=1; i<=diff; i++){
                tempA=tempA->next;
            }
            while(tempA!=tempB){
                tempA=tempA->next;
                tempB=tempB->next;
            }
            return tempA;
        }else{
            int diff=len2-len1;
            for(int i=1; i<=diff; i++){
                tempB=tempB->next;
            }
            while(tempA!=tempB){
                tempA=tempA->next;
                tempB=tempB->next;
            }
            return tempB;
        }
    }
};