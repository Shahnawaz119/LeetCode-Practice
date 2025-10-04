class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int currAtt=0;
        int maxAtt=0;
        for(int i=0; i<gain.size(); i++){
            currAtt+=gain[i];
            if(currAtt>maxAtt){
                maxAtt=currAtt;
            }
        }
        return maxAtt;
    }
};