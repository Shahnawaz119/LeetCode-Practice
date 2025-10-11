class Solution {
public:
    int getLucky(string s, int k) {
        string numStr="";
        for(int i=0; i<s.length(); i++){
            numStr+=to_string(s[i]-'a'+1);
        }
        long long total=0;
        for(int i=0; i<numStr.length(); i++){
            total+=numStr[i]-'0';
        }
        while(--k>0){
            int next=0;
            while(total>0){
                next+=total%10;
                total/=10;
            }
            total=next;
        }
        return total;
    }
};