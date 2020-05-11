// 35. Search Insert Position

static auto io=[](){ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);return 0;}();
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int lo=0,hi=nums.size()-1,mid,ans=nums.size();
        while(lo<=hi){
            mid=lo+(hi-lo)/2;
            if(nums[mid]==target){
                ans=mid;
                break;
            }
            else if(nums[mid]<target)
                lo=mid+1;
            else{
                ans=mid;
                hi=mid-1;
            }
        }
        return ans;
    }
};
