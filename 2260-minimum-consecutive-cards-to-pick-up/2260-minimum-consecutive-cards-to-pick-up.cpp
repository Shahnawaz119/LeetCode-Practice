class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        unordered_map<int,int> mp;
        int minCard=INT_MAX;
        for(int i=0; i<cards.size(); i++){
            if(mp.find(cards[i])!=mp.end()){
                minCard=min(minCard,i-mp[cards[i]]+1);
            }
            mp[cards[i]]=i;
        }
        return minCard==INT_MAX?-1:minCard;
    }
};