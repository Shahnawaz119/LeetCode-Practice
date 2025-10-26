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
    int numComponents(ListNode* head, vector<int>& nums) {
        unordered_set<int> s;
        for(int i=0; i<nums.size(); i++){
            s.insert(nums[i]);
        }
        ListNode* temp=head;
        int count=0;
        while(temp){
            if(s.count(temp->val) && (!temp->next || !s.count(temp->next->val))){
                count++;
            }
            temp=temp->next;
        }
        return count;
    }
};