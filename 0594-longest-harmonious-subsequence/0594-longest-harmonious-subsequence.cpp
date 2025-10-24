class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int,int> map;
        for(int i=0; i<nums.size(); i++){
            map[nums[i]]++;
        }
        int result=0;
        for(int i=0; i<nums.size(); i++){
            int minNum=nums[i];
            int maxNum=nums[i]+1;
            if(map.count(maxNum)){
                result=max(result,map[minNum]+map[maxNum]);
            }
        }
        return result;
    }
};