// 34. Find First and Last Position of Element in Sorted Array

static auto io=[](){ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);return 0;}();
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target){
        int lo,hi,mid,i1,i2;
        lo=0,hi=nums.size()-1,i1=-1,i2=-1;
        while(lo<=hi){
            mid=lo+(hi-lo)/2;
            if(nums[mid]==target)
                i1=mid;
            if(nums[mid]<=target)
                lo=mid+1;
            else
                hi=mid-1;
        }
        lo=0,hi=nums.size()-1;
        while(lo<=hi){
            mid=lo+(hi-lo)/2;
            if(nums[mid]==target)
                i2=mid;
            if(nums[mid]>=target)
                hi=mid-1;
            else
                lo=mid+1;
        }
        vector<int> v;
        v.push_back(i2);
        v.push_back(i1);
        return v;
    }
};