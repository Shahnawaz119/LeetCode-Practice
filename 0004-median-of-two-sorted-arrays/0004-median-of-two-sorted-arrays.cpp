class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> mergeArr;
        int n=nums1.size();
        int m=nums2.size();
        int i=0,j=0;
        while(i<n && j<m){
            if(nums1[i]<nums2[j]){
                mergeArr.push_back(nums1[i++]);
            }else{
                mergeArr.push_back(nums2[j++]);
            }
        }
        while(i<n){
            mergeArr.push_back(nums1[i++]);
        }
        while(j<m){
            mergeArr.push_back(nums2[j++]);
        }
        int size=mergeArr.size();
        if(size%2==0){
            return (double)(mergeArr[(size/2)-1]+mergeArr[size/2])/2.0;
        }
        return (double)(mergeArr[size/2]);
    }
};