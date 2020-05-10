// 704. Binary Search

static auto io=[](){ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);return 0;}();
class Solution {
public:
    int search(vector<int>& nums, int target){
        int ans=-1;
        int lo=0,hi=nums.size()-1,mid;
        while(lo<=hi){
            mid=(lo+hi)/2;
            if(nums[mid]==target)
                return mid;
            else if(nums[mid]>target)
                hi=mid-1;
            else
                lo=mid+1;
        }
        return -1;
    }
};
