class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n=nums.size();
        priority_queue<pair<int,int>> pq;
        for(int i=0; i<n; i++){
            pq.push({nums[i],i});
        }
        vector<pair<int,int>> temp;
        while(k>0){
            temp.push_back(pq.top());
            pq.pop();
            k--;
        }

        sort(temp.begin(),temp.end(), [](auto &a,auto &b){
            return a.second<b.second;
        });
        vector<int> ans;
        for(int i=0; i<temp.size(); i++){
            ans.push_back(temp[i].first);
        }
        return ans;
    }
};