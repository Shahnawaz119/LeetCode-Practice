class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        vector<string> arr;
        for(int i=0; i<paragraph.length(); i++){
            if(isalpha(paragraph[i])){
                int j=i;
                while(j<paragraph.length() && paragraph[j]!=' ' && isalpha(paragraph[j])){
                    j++;
                }
                string word=paragraph.substr(i,j-i);
                for(char &ch:word){
                    ch=tolower(ch);
                }
                arr.push_back(word);
                i=j-1;
            }
        }
        unordered_map<string,int> map;
        for(int i=0; i<arr.size(); i++){
            map[arr[i]]++;
        }
        for(string &b:banned){
            for(char &ch:b){
                ch=tolower(ch);
            }
            map.erase(b);

        }
        int max_common=0;
        string ans="";
        for(auto &m:map){
            int second=m.second;
            string first=m.first;
            if(max_common<second){
                max_common=second;
                ans=first;
            }
        }
        return ans;
        
    }
};