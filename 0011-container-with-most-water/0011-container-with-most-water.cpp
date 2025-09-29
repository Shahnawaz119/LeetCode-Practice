class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxWater=0;
        int n=height.size();
        int leftPointer=0;
        int rightPointer=n-1;
        while(leftPointer<rightPointer){
            int w=rightPointer-leftPointer;
            int ht=min(height[leftPointer],height[rightPointer]);
            int currWater=ht*w;
            maxWater=max(currWater,maxWater);
            if(height[leftPointer]<height[rightPointer]){
                leftPointer++;
            }else{
                rightPointer--;
            }
        }
        return maxWater;
    }
};