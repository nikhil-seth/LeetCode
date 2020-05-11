// 154. Find Minimum in Rotated Sorted Array II
static auto io=[](){ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);return 0;}();
class Solution {
public:
    int findMin(vector<int>& nums){
        int lo=0,hi=nums.size()-1,mid;
        while(lo<hi){
            mid=lo+(hi-lo)/2;
            if(nums[mid]>nums[hi])
                lo=mid+1;
            else if(nums[mid]<nums[hi])
                hi=mid;
            else
                hi-=1;
        }
        return nums[hi];
    }
};
