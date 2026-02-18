class NumArray {
public:
    vector<int> nums;
    vector<int> prefix;
    NumArray(vector<int>& nums) {
        this->nums=nums;
        int n=nums.size();
        prefix.resize(n);
        prefix[0]=nums[0];
        for(int i=1; i<n; i++){
            prefix[i]=prefix[i-1]+nums[i];
        }
    }
    void update(int index, int val) {
        if(index<0 || index>=nums.size()){
            return;
        }
        int diff=val-nums[index];
        nums[index]=val;
        for(int i=index; i<prefix.size(); i++){
            prefix[i]+=diff;
        }
        
    }
    
    int sumRange(int left, int right) {
        if(left==0){
            return prefix[right];
        }
        return prefix[right]-prefix[left-1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */