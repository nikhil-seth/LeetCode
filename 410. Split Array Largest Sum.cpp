// 410. Split Array Largest Sum
class Solution {
public:
    int splitArray(vector<int>& nums, int m){
        long long hi=0,mid,ts,ctr;
        int lo=0;
        for(auto c:nums){
            lo=max(lo,c); hi+=c;
        }
        while(lo<hi){
            mid=lo+(hi-lo)/2;
            ctr=1,ts=0;
            for(int i=0;i<nums.size();i+=1){
                if(nums[i]+ts>mid){
                    ctr+=1;
                    ts=nums[i];
                }
                else
                    ts+=nums[i];
                if(ctr>m)
                    break;
            }
            if(ctr>m)
                lo=mid+1;
            else
                hi=mid;
        }
        return hi;
    }
};
