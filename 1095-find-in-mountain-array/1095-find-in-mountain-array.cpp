/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int PeakIndex(MountainArray &arr){
        int n=arr.length();
        int i=0;
        int j=n-1;
        while(i<j){
            int mid=i+(j-i)/2;
            if(arr.get(mid)>arr.get(mid+1)){
                j=mid;
            }else{
                i=mid+1;
            }
        }
        return i;
    }
    int leftBinarySearch(MountainArray &mountainArr,int i,int j,int target){
        while(i<=j){
            int mid=i+(j-i)/2;
            if(mountainArr.get(mid)==target){
                return mid;
            }else if(mountainArr.get(mid)>target){
                j=mid-1;
            }else{
                i=mid+1;
            }
        }
        return -1;
    }
    int rightBinarySearch(MountainArray &mountainArr,int i,int j,int target){
        while(i<=j){
            int mid=i+(j-i)/2;
            if(mountainArr.get(mid)==target){
                return mid;
            }else if(mountainArr.get(mid)>target){
                i=mid+1;
            }else{
                j=mid-1;
            }
        }
        return -1;
    }
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n=mountainArr.length();
        int PeakIdx=PeakIndex(mountainArr);
        int result_idx=leftBinarySearch(mountainArr,0,PeakIdx,target);
        if(result_idx!=-1){
            return result_idx;
        }
        result_idx=rightBinarySearch(mountainArr,PeakIdx,n-1,target);
        return result_idx;
    }
};