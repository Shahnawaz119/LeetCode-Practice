class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n=strs.size();
        int m=strs[0].size();
        vector<bool> fixed(n-1,false);
        int count=0;
        for(int i=0; i<m; i++){
            bool flag=false;
            int j=0;
            while(j<n-1){
                if(!fixed[j] && strs[j][i]>strs[j+1][i]){
                    flag=true;
                    break;
                }
                j++;
            }
            if(flag){
                count++;
                continue;
            }
            j=0;
            while(j<n-1){
                if(!fixed[j] && strs[j][i]<strs[j+1][i]){
                    fixed[j]=true;
                }
                j++;
            }
        }
        return count;
    }
};