class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        unordered_map<string,int>map1,map2;
        for(int i=0; i<words1.size(); i++){
            map1[words1[i]]++;
        }
        for(int i=0; i<words2.size();i++){
            map2[words2[i]]++;
        }
        int count=0;
        for(auto &it:map1){
            if(it.second==1 && map2[it.first]==1){
                count++;
            }
        }
        return count;
        
    }
};