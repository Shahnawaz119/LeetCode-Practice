class Solution {
public:
    int minimumDeletions(string s) {
        int n=s.length();
        vector<int> countA(n,0);
        vector<int> countB(n,0);
        int currA=0;
        int currB=0;
        for(int i=n-1; i>=1; i--){
            if(s[i]=='a'){
                currA++;
            }
            countA[i-1]=currA;
        }
        for(int i=0; i<n-1; i++){
            if(s[i]=='b'){
                currB++;
            }
            countB[i+1]=currB;
        }
        int count=INT_MAX;
        for(int i=0; i<n; i++){
            if(i==0){
                count=min(count,countA[i]);
            }
            if(i==n-1){
                count=min(count,countB[i]);
            }
            if(i>0 && i<n-1){
                count=min(count,countA[i]+countB[i]);
            }
        }
        return count;
    }
};