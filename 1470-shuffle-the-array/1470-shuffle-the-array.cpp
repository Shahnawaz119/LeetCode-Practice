class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> arr1;
        vector<int> arr2;
        for(int i=0; i<n; i++){
            arr1.push_back(nums[i]);
            arr2.push_back(nums[n+i]);
        }
        int idx1=0;
        int idx2=1;
        for(int i=0; i<n; i++){
            nums[idx1]=arr1[i];
            nums[idx2]=arr2[i];
            idx1=idx1+2;
            idx2=idx2+2;
        }
        return nums;
    }
};