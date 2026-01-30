class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n=numbers.size();
        vector<int> ans;
        for(int k=0; k<n; k++){
            int i=0;
            int j=n-1;
            while(i<=j){
                int sum=numbers[i]+numbers[j];
                if(sum==target){
                    return {i+1,j+1};
                }else if(sum<target){
                    i++;
                }else{
                    j--;
                }
            }
        }
        return ans;
    }
};