class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()){
            return 0;
        }
        unordered_set<int> s(nums.begin(),nums.end());
        int ans=0;
        for(auto i=s.begin(); i!=s.end(); i++){
            int num=*i;
            if(!s.count(num-1)){
                int current=num;
                int count=1;
                while(s.count(current+1)){
                    count++;
                    current++;
                }
                ans=max(ans,count);
            }
        }
        return ans;
    }
};