class Solution {
public:
    int minOperations(string s) {
        int n=s.length();
        int way1=0;
        int way2=0;
        for(int i=0; i<n; i++){
            if(i%2==0 && s[i]!='0'){
                way1++;
            }
            if(i%2==1 && s[i]!='1'){
                way1++;
            }

            if(i%2==0 && s[i]!='1'){
                way2++;
            }
            if(i%2==1 && s[i]!='0'){
                way2++;
            }
        }
        return min(way1,way2);
    }
};