class Solution {
public:
    string minWindow(string s, string t) {
        int n=s.length();
        int total=t.length();
        unordered_map<char,int> map;
        for(int i=0; i<t.length(); i++){
            map[t[i]]++;
        }
        int start=0,end=0;
        int ans=INT_MAX;
        int index=-1;
        while(end<n){
            map[s[end]]--;
            if(map[s[end]]>=0){
                total--;
            }

            while(!total && start<=end){
                if(ans>end-start+1){
                    ans=end-start+1;
                    index=start;
                }
                map[s[start]]++;
                if(map[s[start]]>0){
                    total++;
                }
                start++;
            }
            end++;
        }

        if(index==-1){
            return "";
        }
        string result="";
        for(int i=index; i<index+ans; i++){
            result+=s[i];
        }
        return result;
    }
};