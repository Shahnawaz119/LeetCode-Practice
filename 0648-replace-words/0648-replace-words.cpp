class Solution {
public:
    string findRoot(string &word,unordered_set<string> &s){
        for(int i=1; i<=word.length(); i++){
            string root=word.substr(0,i);
            if(s.count(root)){
                return root;
            }
        }
        return word;
    }
    string replaceWords(vector<string>& dictionary, string sentence) {
        unordered_set<string> s(dictionary.begin(),dictionary.end());
        vector<string> words;
        for(int i=0; i<sentence.length(); i++){
            if(sentence[i]!=' '){
                int j=i;
                while(j<sentence.length() && sentence[j]!=' '){
                    j++;
                }
                words.push_back(sentence.substr(i,j-i));
                i=j-1;
            }
        }
        string result="";
        for(int i=0; i<words.size(); i++){
            string word=words[i];
            result+=findRoot(word,s)+" ";
        }
        result.pop_back();
        return result;
    }
};