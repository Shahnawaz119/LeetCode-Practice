class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int leftPtr=0;
        int rightPtr=n-1;
        int maxArea=INT_MIN;
        while(leftPtr<rightPtr){
            int wt=rightPtr-leftPtr;
            int ht=min(height[leftPtr],height[rightPtr]);
            int currArea=wt*ht;
            maxArea=max(maxArea,currArea);
            if(height[leftPtr]<height[rightPtr]){
                leftPtr++;
            }else{
                rightPtr--;
            }
        }
        return maxArea;
    }
};