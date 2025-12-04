class Solution {
public:
    int countCollisions(string directions) {
        int n=directions.length();
        int count=0;
        int i=0,j=n-1;
        while(i<n && directions[i]=='L'){
            i++;
        }
        while(j>=0 && directions[j]=='R'){
            j--;
        }
        string str=directions.substr(i,j-i+1);
        for(int i=0; i<str.length(); i++){
            if(str[i]=='L' || str[i]=='R'){
                count++;
            }
        }
        return count;
    }
};