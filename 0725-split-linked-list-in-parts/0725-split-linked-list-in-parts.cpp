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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        ListNode* curr=head;
        int len=0;
        while(curr){
            len++;
            curr=curr->next;
        }
        curr=head;
        vector<ListNode*> result(k,NULL);
        if(k>len){
            k=len;
        }
        int eachBucketNode = len/k;
        int remainderNode=len%k;
        ListNode* prev=NULL;
        for(int i=0; i<k; i++){
            ListNode* prev=NULL;
            result[i]=curr;
            for(int count=1; count<=eachBucketNode+(remainderNode>0 ? 1:0); count++){
                prev=curr;
                curr=curr->next;
            }
            prev->next=NULL;
            remainderNode--;
        }
        return result;
    }
};