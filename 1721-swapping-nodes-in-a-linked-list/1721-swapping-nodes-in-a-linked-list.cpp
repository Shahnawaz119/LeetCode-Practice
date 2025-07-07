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
    void reverse(vector<int>&arr,int k){
        int n=arr.size();
        int i=k-1;
        int j=n-k;
        while(i<j){
            swap(arr[i],arr[j]);
            i++;
            j--;
        }
    }
    ListNode* builList(ListNode* head,int val){
        ListNode* newNode=new ListNode(val);
        if(head==NULL){
            head=newNode;
        }else{
            ListNode* curr=head;
            while(curr->next!=NULL){
                curr=curr->next;
            }
            curr->next=newNode;
        }
        return head;
    }
    ListNode* swapNodes(ListNode* head, int k) {
        if(head==NULL || k==0){
            return head;
        }
        vector<int> arr;
        ListNode* curr=head;
        while(curr){
            arr.push_back(curr->val);
            curr=curr->next;
        }
        reverse(arr,k);
        ListNode* newHead=NULL;
        for(int i=0; i<arr.size(); i++){
            newHead=builList(newHead,arr[i]);
        }
        return newHead;
    }
};