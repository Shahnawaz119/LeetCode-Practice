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
        ListNode* temp=new ListNode(100);
        ListNode* c=temp;
        while(a!=NULL && b!=NULL){
            if(a->val<=b->val){
                c->next=a;
                a=a->next;
                c=c->next;
            }else{
                c->next=b;
                b=b->next;
                c=c->next;
            }
        }
        if(a!=NULL){
            c->next=a;
        }else{
            c->next=b;
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