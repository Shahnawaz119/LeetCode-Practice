class Solution {
public:
    string minWindow(string s, string t) {
        int total=t.length();
        int left=0;
        int right=0;
        int len=INT_MAX;
        unordered_map<int,int> map;
        for(int i=0; i<total; i++){
            map[t[i]]++;
        }
        int n=s.length();
        int index=-1;
        while(right<n){
            map[s[right]]--;
            if(map[s[right]]>=0){
                total--;
            }

            while(!total && left<=right){
                if(len>right-left+1){
                    len=right-left+1;
                    index=left;
                }
                map[s[left]]++;
                if(map[s[left]]>0){
                    total++;
                }
                left++;
            }
            right++;
        }

        if(index==-1){
            return "";
        }
        string ans="";
        for(int i=index; i<index+len; i++){
            ans+=s[i];
        }
        return ans;
    }
};