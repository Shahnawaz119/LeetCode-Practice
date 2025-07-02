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
    ListNode* marge(ListNode* a,ListNode* b){
        if(a==NULL && b==NULL){
            return NULL;
        }
        ListNode* temp=new ListNode(0);
        ListNode* start=temp;
        while(a!=NULL && b!=NULL){
            if(a->val<=b->val){
                start->next=a;
                start=start->next;
                a=a->next;
            }else{
                start->next=b;
                start=start->next;
                b=b->next;
            }
        }
        if(a!=NULL){
            start->next=a;
        }else{
            start->next=b;
        }
        return temp->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0){
            return NULL;
        }
        while(lists.size()>1){
            ListNode* a=lists[lists.size()-1];
            lists.pop_back();
            ListNode* b=lists[lists.size()-1];
            lists.pop_back();
            ListNode* newNode=marge(a,b);
            lists.push_back(newNode);
        }
        return lists[0];
    }
};