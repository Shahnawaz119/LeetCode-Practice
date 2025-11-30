class Solution {
public:
    vector<int> divisibilityArray(string word, int m) {
        int n=word.size();
        vector<int> arr(n,0);
        int sum=0;
        for(int i=0; i<n; i++){
            int num=word[i]-'0';
            sum=(sum*10+num)%m;
            if(sum==0){
                arr[i]=1;
            }
        }
        return arr;
    }
};