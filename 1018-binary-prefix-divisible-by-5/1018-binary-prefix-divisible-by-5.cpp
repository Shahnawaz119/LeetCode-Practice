class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int n=nums.size();
        vector<bool> ans;
        signed int num=0;
        for(int i=0; i<n; i++){
            num=num*10+nums[i];
            signed int temp=num;
            int pow=1;
            int value=0;
            while(temp>0){
                int rem=temp%10;
                value=value+rem*pow;
                pow=pow*2;
                temp=temp/10;
            }
            if(value%5==0){
                ans.push_back(true);
            }else{
                ans.push_back(false);
            }
        }
        return ans;
    }
};