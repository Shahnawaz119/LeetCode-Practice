class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string,int> map1;
        for(int i=0; i<s1.length(); i++){
            if(s1[i]!=' '){
                int j=i;
                while(j<s1.length() && s1[j]!=' '){
                    j++;
                }
                map1[s1.substr(i,j-i)]++;
                i=j-1;
            }
        }
        unordered_map<string,int> map2;
        for(int i=0; i<s2.length(); i++){
            if(s2[i]!=' '){
                int j=i;
                while(j<s2.length() && s2[j]!=' '){
                    j++;
                }
                map2[s2.substr(i,j-i)]++;
                i=j-1;
            }
        }
        vector<string> ans;
        for(auto &it:map1){
            if(it.second==1){
                if(map2.find(it.first)==map2.end()){
                    ans.push_back(it.first);
                }
            }
        }
        for(auto &it:map2){
            if(it.second==1){
                if(map1.find(it.first)==map1.end()){
                    ans.push_back(it.first);
                }
            }
        }
        return ans;
    }
};