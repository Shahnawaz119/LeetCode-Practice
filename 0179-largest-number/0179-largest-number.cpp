class Solution {
public:

    string largestNumber(vector<int>& nums) {
        auto myComp=[](int &a1,int &a2){
            string s1=to_string(a1);
            string s2=to_string(a2);
            if(s1+s2>s2+s1){
                return true;
            }
            return false;
        };
        sort(nums.begin(),nums.end(),myComp);

        if(nums[0]==0){
            return '0';
        }

        string result="";
        for(int i=0; i<nums.size(); i++){
            result+=to_string(nums[i]);
        }
        return result;
    }
};