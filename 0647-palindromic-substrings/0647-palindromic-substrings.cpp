class Solution {
public:
    int arr[1001][1001];
    bool isPalindrome(int i,int j,string &s){
        if(i>=j){
            return true;
        }
        if(arr[i][j]!=-1){
            return arr[i][j];
        }
        if(s[i]==s[j]){
           return  arr[i][j]=isPalindrome(i+1,j-1,s);
        }
        return arr[i][j]=false;
    }
    int countSubstrings(string s) {
        int count=0;
        int n=s.length();
        memset(arr,-1,sizeof(arr));
        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                if(isPalindrome(i,j,s)){
                    count++;
                }
            }
        }
        return count;
    }
};