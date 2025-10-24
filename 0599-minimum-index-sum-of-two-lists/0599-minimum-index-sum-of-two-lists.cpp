class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string,int> map1;
        for(int i=0; i<list1.size(); i++){
            map1[list1[i]]=i;
        }
        vector<string> ans;
        int minSum=INT_MAX;
        for(int i=0; i<list2.size(); i++){
            string word=list2[i];
            if(map1.find(word)!=map1.end()){
                int sum=i+map1[word];
                if(sum<minSum){
                    minSum=sum;
                    ans={word};
                }else if(sum==minSum){
                    ans.push_back(word);
                }
            }
        }
        return ans;

    }
};