class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n=nums.size();
        int currSum=0;
        unordered_map<int,int> map;
        map[0]=1;
        int count=0;
        for(int i=0; i<n; i++){
            currSum+=nums[i];
            if(map.find(currSum-goal)!=map.end()){
                count+=map[currSum-goal];
            }
            map[currSum]++;
        }
        return count;
    }
};