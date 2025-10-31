class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int,int>map;
        for(auto a:nums1){
            for(auto b:nums2){
                map[a+b]++;
            }
        }
        int count=0;
        for(auto a:nums3){
            for(auto b:nums4){
                int target=-(a+b);
                if(map.find(target)!=map.end()){
                    count+=map[target];
                }
            }
        }
        return count;
    }
};