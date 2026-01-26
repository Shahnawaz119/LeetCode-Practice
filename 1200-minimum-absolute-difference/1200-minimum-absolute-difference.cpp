class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>> ans;
        int n=arr.size();
        sort(arr.begin(),arr.end());
        int minAbsDiff=INT_MAX;
        for(int i=1; i<n; i++){
            if(abs(arr[i]-arr[i-1])<minAbsDiff){
                minAbsDiff=abs(arr[i]-arr[i-1]);
            }
        }
        for(int i=1; i<n; i++){
            if(abs(arr[i]-arr[i-1])==minAbsDiff){
                ans.push_back({arr[i-1],arr[i]});
            }
        }
        return ans;
    }
};