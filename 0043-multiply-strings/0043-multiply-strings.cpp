class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1=="0" || num2=="0"){
            return "0";
        }
        reverse(num1.begin(),num1.end());
        reverse(num2.begin(),num2.end());
        int m=num1.size();
        int n=num2.size();
        vector<int> v(n+m+1,0);
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                v[i+j]+=(num1[i]-'0')*(num2[j]-'0');
            }
        }
        reverse(v.begin(),v.end());
        for(int i=n+m; i>=1; i--){
            v[i-1]=v[i-1]+v[i]/10;
            v[i]=v[i]%10;
        }
        int first=0;
        while(first<=n+m && v[first]==0){
            first++;
        }
        string result="";
        for(int i=first; i<=n+m; i++){
            result+=to_string(v[i]);
        }
        return result;
    }
};