class Solution {
public:
    bool isSubsequence(string s,unordered_map<char,vector<int>> &pos){
        int prev=-1;
        for(int i=0; i<s.size(); i++){
            char ch=s[i];
            if(pos.find(ch)==pos.end()){
                return false;
            }
            auto vec=pos[ch];
            auto it=upper_bound(vec.begin(),vec.end(),prev);
            if(it==vec.end()){
                return false;
            }
            prev=*it;
        }
        return true;
    }
    int numMatchingSubseq(string s, vector<string>& words) {
        unordered_map<char,vector<int>> pos;
        for(int i=0; i<s.size(); i++){
            pos[s[i]].push_back(i);
        }
        int count=0;
        for(int i=0; i<words.size(); i++){
            if(isSubsequence(words[i],pos)){
                count++;
            }
        }
        return count;
    }
};