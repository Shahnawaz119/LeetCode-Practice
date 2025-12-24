class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        sort(capacity.rbegin(),capacity.rend());
        int sum=0;
        int count=0;
        for(int i=0; i<apple.size(); i++){
            sum+=apple[i];
        }
        int currSum=0;
        int result=0;
        for(int i=0; i<capacity.size(); i++){
            currSum+=capacity[i];
            if(currSum>=sum){
                result=i+1;
                break;
            }
        }
        return result;
    }

};