class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char,int> map;
        for(int i=0; i<s.length(); i++){
            map[s[i]]++;
        }
        char ch;
        for(int i=0; i<t.length(); i++){
            if(map.find(t[i])!=map.end()){
                map[t[i]]--;
                if(map[t[i]]==0){
                    map.erase(t[i]);
                }
            }else{
                ch=t[i];
                break;
            }
        }
        return ch;
    }
};