// 523. Continuous Subarray Sum
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        if(n<2)
            return 0;
        if(k<0)
            k*=-1;
        unordered_set<int> dp;
        int x=0,prev=0,mod;
        for(int i=0;i<nums.size();i++){
            x+=nums[i];
            mod=k==0?x:x%k;
            if(dp.count(mod))
                return 1;
            dp.insert(prev);
            prev=mod;
        }
        return 0;
    }
};
