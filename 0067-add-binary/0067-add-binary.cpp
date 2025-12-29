class Solution {
public:
    string addBinary(string a, string b) {
        int alen=a.length();
        int blen=b.length();
        string result="";
        int carry=0;
        int i=0;
        while(i<alen || i<blen || carry!=0){
            int x=0;
            if(i<alen && a[alen-1-i]=='1'){
                x=1;
            }
            int y=0;
            if(i<blen && b[blen-1-i]=='1'){
                y=1;
            }
            result=to_string((x+y+carry)%2)+result;
            carry=(x+y+carry)/2;
            i++;
        }
        return result;
    }
};