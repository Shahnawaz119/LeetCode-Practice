class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        int countOnes=0;
        for(int i=0; i<n; i++){
            if(nums[i]==1){
                countOnes++;
            }
        }
        if(countOnes>0){
            return n-countOnes;
        }
        int minOpe=INT_MAX;
        for(int i=0; i<n; i++){
            int GCD=nums[i];
            for(int j=i+1; j<n;  j++){
                GCD=gcd(GCD,nums[j]);
                if(GCD==1){
                    minOpe=min(minOpe,j-i);
                    break;
                }
            }
        }

        return minOpe==INT_MAX? -1:(minOpe+n-1);
    }
};