class Solution {
public:
    int Operate(int a,int b,string &str){
        if(str=="+"){
            return a+b;
        }
        if(str=="-"){
            return a-b;
        }
        if(str=="*"){
            return a*b;
        }
        if(str=="/"){
            return a/b;
        }
        return 0;
    }
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(int i=0; i<tokens.size(); i++){
            if(tokens[i]=="+" || tokens[i]=="-" || tokens[i]=="*" || tokens[i]=="/"){
                int right=st.top();
                st.pop();
                int left=st.top();
                st.pop();
                int result=Operate(left,right,tokens[i]);
                st.push(result);
            }else{
                st.push(stoi(tokens[i]));
            }
        }
        return st.top();
    }
};