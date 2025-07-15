class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size()+1;
        int m=nums2.size()+1;
        vector<vector<int>> arr(n,vector<int> (m,0));
        int ans=0;
        for(int i=1; i<n; i++){
            for(int j=1; j<m; j++){
                if(nums1[i-1]==nums2[j-1]){
                    arr[i][j]=arr[i-1][j-1]+1;
                    ans=max(ans,arr[i][j]);
                }else{
                    arr[i][j]=0;
                }
            }
        }
        return ans;
    }
};