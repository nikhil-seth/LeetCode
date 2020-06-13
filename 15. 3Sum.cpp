// 15. 3Sum
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums){
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        vector<vector<int>> vx;
        int n=nums.size();
        if(n<3) return vx;
        sort(nums.begin(),nums.end());
        int lo,hi,ts;
        for(int i=0;i<n-2;i+=1){
            if(nums[i]>0) break;
            if((i>0) && nums[i]==nums[i-1]) continue;
            lo=i+1,hi=n-1;
            while(lo<hi){
                if(nums[hi]<0) break;
                ts=nums[lo]+nums[hi];
                if(ts<-nums[i])
                    lo+=1;
                else if(ts>-nums[i])
                    hi-=1;
                else{
                    vx.push_back({nums[i],nums[lo],nums[hi]});
                    lo+=1;
                    hi-=1;
                    while(lo<n-1 && lo>0 && nums[lo]==nums[lo-1]) lo+=1;
                    while(hi>=0 && hi<n-1 && nums[hi]==nums[hi+1]) hi-=1;
                }
            }
        }
        return vx;
    }
};
