// 1283. Find the Smallest Divisor Given a Threshold

static auto io=[](){ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);return 0;}();
class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold){
        int lo,hi,mid,ctr;
        lo=hi=1;
        for(auto c:nums)
            hi=max(hi,c);
        while(lo<hi){
            mid=lo+(hi-lo)/2;
            ctr=0;
            for(int i=0;i<nums.size();i+=1)
                ctr+=ceil(float(nums[i])/mid);
            if(ctr>threshold)
                lo=mid+1;
            else
                hi=mid;
        }
        return hi;
    }
};
