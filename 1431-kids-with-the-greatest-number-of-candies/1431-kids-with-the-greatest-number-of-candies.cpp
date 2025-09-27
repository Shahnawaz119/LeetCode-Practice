class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int greatest=INT_MIN;
        for(int i=0; i<candies.size(); i++){
            if(greatest<candies[i]){
                greatest=candies[i];
            }
        }
        vector<bool> arr(candies.size(),false);
        for(int i=0; i<candies.size(); i++){
            if(candies[i]+extraCandies>=greatest){
                arr[i]=true;
            }
        }
        return arr;
    }
};