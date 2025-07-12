class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int target) {
        int n=arr.size();
        vector<int> ans;
        for(int k=0; k<n; k++){
            int i=0;
            int j=n-1;
            while(i<j){
                int sum=arr[i]+arr[j];
                if(sum==target){
                    ans.push_back(i+1);
                    ans.push_back(j+1);
                    return ans;
                }else if(sum>target){
                    j--;
                }else{
                    i++;
                }
            }
        }
        return ans;
    }
};