class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int,int> count,start,end;
        int max_degree=0;
        for(int i=0; i<nums.size(); i++){
            if(count[nums[i]]==0){
                start[nums[i]]=i;
                end[nums[i]]=i;
            }else{
                end[nums[i]]=i;
            }
            count[nums[i]]++;
            max_degree=max(max_degree,count[nums[i]]);
        }

        int Len=INT_MAX;
        for(auto &m:count){
            if(m.second==max_degree){
                Len=min(Len,end[m.first]-start[m.first]+1);
            }
        }
        return Len;
    }

};