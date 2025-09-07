class Solution {
public:
    bool hasMatch(string s, string p) {
        int starPos=p.find('*');
        string prefix=p.substr(0,starPos);
        string suffix=p.substr(starPos+1);
        int i=s.find(prefix);
        return i!=string::npos && s.find(suffix,i+prefix.length())!=string::npos;
    }
};