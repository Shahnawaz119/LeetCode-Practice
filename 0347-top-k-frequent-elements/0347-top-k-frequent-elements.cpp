class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        for(auto x:nums){
            map[x]++;
        }
        priority_queue<pair<int,int>>maxHeap;
        for(auto x:map){
            maxHeap.push({x.second,x.first});
        }
        vector<int>ans;
        while(!maxHeap.empty() && k>0){
            ans.push_back(maxHeap.top().second);
            maxHeap.pop();
            k--;
        }
        return ans;
    }
};