// 1095. Find in Mountain Array

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
    int findInMountainArray(int target, MountainArray &arr){
        static auto io=[](){ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);return 0;}();
        int n=arr.length(),lo=0,hi=n-1,mid,peak,x;
        while(lo<hi){
            mid=lo+(hi-lo)/2;
            if(arr.get(mid)<arr.get(mid+1))
                lo=mid+1;
            else
                hi=mid;
        }
        peak=hi;
        //cout<<peak<<endl;
        lo=0,hi=peak;
        while(lo<=hi){
            mid=lo+(hi-lo)/2;
            x=arr.get(mid);
            if(x==target)
                return mid;
            else if(x<target)
                lo=mid+1;
            else
                hi=mid-1;
        }
        lo=peak+1,hi=n-1;
        while(lo<=hi){
            mid=lo+(hi-lo)/2;
            x=arr.get(mid);
            if(x==target)
                return mid;
            else if(x>target)
                lo=mid+1;
            else
                hi=mid-1;
        }
        return -1;
    }
};
