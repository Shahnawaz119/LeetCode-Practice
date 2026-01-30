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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummy=new ListNode(0);
        dummy->next=head;
        ListNode* leftPrev=dummy;
        ListNode* currNode=head;
        for(int i=0; i<left-1; i++){
            leftPrev=leftPrev->next;
            currNode=currNode->next;
        }
        ListNode* subListhead=currNode;
        ListNode* prev=NULL;
        for(int i=0; i<=right-left; i++){
            ListNode* nextNode=currNode->next;
            currNode->next=prev;
            prev=currNode;
            currNode=nextNode;
        }
        leftPrev->next=prev;
        subListhead->next=currNode;
        return dummy->next;
    }
};