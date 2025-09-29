class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> map;
        for(int i=0; i<arr.size(); i++){
            map[arr[i]]++;
        }
        unordered_map<int,int> map1;
        for(auto &it : map){
            map1[it.second]++;
        }
        for(auto &it : map1){
            if(it.second!=1){
                return false;
            }
        }
        return true;
    }
};