// 81. Search in Rotated Sorted Array II
class Solution {
public:
    bool search(vector<int>& nums, int target){
        int lo=0,hi=nums.size()-1,mid;
        while(lo<=hi){
            mid=lo+(hi-lo)/2;
            if(nums[mid]==target)
                return 1;
            while(nums[lo]==nums[mid] && lo!=mid)
                lo+=1;
            while(nums[hi]==nums[mid] && hi!=mid)
                hi-=1;
            if(nums[lo]<=nums[mid]){
                if(target>=nums[lo] && target<=nums[mid])
                    hi=mid-1;
                else
                    lo=mid+1;
            }
            else{
                if(target>=nums[mid] && target<=nums[hi])
                    lo=mid+1;
                else
                    hi=mid-1;
            }
        }
        return 0;
    }
};
