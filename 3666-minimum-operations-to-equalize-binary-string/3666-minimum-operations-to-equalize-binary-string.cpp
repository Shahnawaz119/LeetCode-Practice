class Solution {
public:
    int minOperations(string s, int k) {
        int n=s.length();
        int startZeros=0;
        for(int i=0; i<n; i++){
            if(s[i]=='0'){
                startZeros++;
            }
        }
        if(startZeros==0){
            return 0;
        }
        set<int>evenSet;
        set<int> oddSet;
        for(int count=0; count<=n; count++){
            if(count%2==0){
                evenSet.insert(count);
            }else{
                oddSet.insert(count);
            }
        }
        vector<int> operations(n+1,-1);
        queue<int> q;
        q.push(startZeros);
        operations[startZeros]=0;
        if(startZeros%2==0){
            evenSet.erase(startZeros);
        }else{
            oddSet.erase(startZeros);
        }
        while(!q.empty()){
            int z=q.front();
            q.pop();
            int minF=max(0,k-n+z);
            int maxF=min(k,z);

            int new_min_z=z + k - 2*maxF;
            int new_max_z=z + k - 2*minF;
            
            set<int> &currSet=(new_min_z%2==0)?evenSet:oddSet;
            auto it=currSet.lower_bound(new_min_z);
            while(it!=currSet.end() && *it<=new_max_z){
                int newZ= *it;
                if(operations[newZ]==-1){
                    operations[newZ]=operations[z]+1;
                    if(newZ==0){
                        return operations[newZ];
                    }
                    q.push(newZ);
                }
                it=currSet.erase(it);
            }
        }
        return -1;
    }
};