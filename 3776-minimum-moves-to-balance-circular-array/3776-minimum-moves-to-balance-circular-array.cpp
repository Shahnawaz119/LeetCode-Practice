class Solution {
public:
    typedef long long ll;
    long long minMoves(vector<int>& balance) {
        int n=balance.size();
        int culPritIndx=-1;
        ll sum=0;
        for(int i=0; i<balance.size(); i++){
            sum+=balance[i];
            if(balance[i]<0){
                culPritIndx=i;
            }
        }
        if(culPritIndx==-1){
            return 0;
        }
        if(sum<0){
            return -1;
        }

        ll move=0;
        int dist=1;
        while(balance[culPritIndx]<0){
            int right=(culPritIndx+dist)%n;
            int left=(culPritIndx-dist+n)%n;

            ll available=balance[left]+balance[right];
            if(left==right){
                available-=balance[left];
            }
            ll needed=-balance[culPritIndx];
            ll taken=min(needed,available);
            move=move+taken*dist;
            balance[culPritIndx]+=taken;
            dist++;
        }

        return move;
    }
};