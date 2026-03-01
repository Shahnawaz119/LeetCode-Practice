class Solution {
public:
    int minPartitions(string n) {
        char maxChar='0';
        for(int i=0; i<n.length(); i++){
            if(maxChar<n[i]){
                maxChar=n[i];
            }
        }
        return maxChar-'0';
    }
};