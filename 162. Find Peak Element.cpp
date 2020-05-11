// 162. Find Peak Element

static auto io=[](){ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);return 0;}();
class Solution {
public:
    int findPeakElement(vector<int>& nums){
        int n=nums.size();
        if(n==0) return -1;
        if(n==1) return 0;
        if(nums[0]>nums[1]) return 0;
        if(nums[n-1]>nums[n-2]) return n-1;
        int lo=0,hi=n-1,mid;
        while(lo<hi){
            mid=lo+(hi-lo)/2;
            if(nums[mid]>nums[mid+1] && nums[mid-1]<nums[mid])
                return mid;
            else if(nums[mid]<nums[mid+1])
                lo=mid+1;
            else
                hi=mid-1;
        }
        return lo;
    }
};
