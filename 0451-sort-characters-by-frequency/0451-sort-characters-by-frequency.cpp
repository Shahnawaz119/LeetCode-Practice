class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>map;
        for(int i=0; i<s.length(); i++){
            map[s[i]]++;
        }

        vector<pair<char,int>> vec(map.begin(),map.end());
        sort(vec.begin(),vec.end(), [](auto &a,auto &b){
            return a.second>b.second;
        });

        string result="";
        for(int i=0; i<vec.size(); i++){
            result.append(vec[i].second,vec[i].first);
        }
        return result;
    }
};