class Solution {
public:
    int compress(vector<char>& chars) {
        int n=chars.size();
        int idx=0;
        for(int i=0; i<n; i++){
            int ch=chars[i];
            int count=0;
            while(i<n && ch==chars[i]){
                count++;
                i++;
            }
            if(count==1){
                chars[idx++]=ch;
            }else{
                chars[idx++]=ch;
                string str=to_string(count);
                for(char dig:str){
                    chars[idx++]=dig;
                }
            }
            i--;
        }
        chars.resize(idx);
        return chars.size();
    }
};