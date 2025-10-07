class Solution {
public:
    string decodeString(string s) {
        stack<int> numStack;
        stack<string> strStack;
        string curr="";
        int num=0;
        for(int i=0; i<s.length(); i++){
            char ch=s[i];
            if(isdigit(s[i])){
                num=num*10+(ch-'0');
            }else if(ch=='['){
                numStack.push(num);
                strStack.push(curr);
                num=0;
                curr="";
            }else if(ch==']'){
                int time=numStack.top();
                numStack.pop();
                string temp=curr;
                curr=strStack.top();
                strStack.pop();
                while(time--){
                    curr+=temp;
                }
            }else{
                curr+=ch;
            }
        }
        return curr;
    }
};