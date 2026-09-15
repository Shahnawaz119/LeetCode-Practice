class Solution {
public:
    string frequencySort(string s) {
        int n=s.length();
        unordered_map<char,int>map;
        for(auto x:s){
            map[x]++;
        }
        priority_queue<pair<int,char>> q;
        for(auto x:map){
            q.push({x.second,x.first});
        }
        string ans="";
        while(!q.empty()){
            for(int i=0; i<q.top().first; i++){
                ans+=q.top().second;
            }
            q.pop();
        }
        return ans;
    }
};