class Solution {
public:
    int numSteps(string s) {
        int n=s.size();
        int steps=0;
        int carry=0;
        for(int i=n-1; i>0; i--){
            int currBit=(s[i]-'0')+carry;
            if(currBit==1){
                steps+=2;
                carry=1;
            }else{
                steps++;
            }
        }
        return steps+carry;
    }
};