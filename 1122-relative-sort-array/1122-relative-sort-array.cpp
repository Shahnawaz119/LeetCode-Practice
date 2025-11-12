class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int,int> mp;
        for(int i=0; i<arr1.size(); i++){
            mp[arr1[i]]++;
        }
        int k=0;
        for(int i=0; i<arr2.size(); i++){
            while(mp[arr2[i]]>0){
                arr1[k++]=arr2[i];
                mp[arr2[i]]--;
            }
        }
        vector<int> rem;
        for(auto m:mp){
            while(m.second>0){
                rem.push_back(m.first);
                m.second--;
            }
        }
        sort(rem.begin(),rem.end());
        for(int i=0; i<rem.size(); i++){
            arr1[k++]=rem[i];
        }

        return arr1;
    }
};