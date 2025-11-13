class Solution {
public:
    int maxOperations(string s) {
        int i=0;
        int result=0;
        int count1seen=0;
        while(i<s.length()){
            if(s[i]=='0'){
                result+=count1seen;
                while(i<s.length() && s[i]=='0'){
                    i++;
                }
            }else{
                count1seen++;
                i++;
            }
        }
        return result;
        
    }
};