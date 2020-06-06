// 494. Target Sum
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S){
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i+=1)
            sum+=nums[i];
        if(n==0 || S>sum || S<-sum) return 0;
        // Sum -ve bhi hosakta h
        // We're given that sum of elements don't exceed 1000.
        int dp[2][sum*2+1];
        memset(dp,0,sizeof(dp));
        dp[n%2][sum]=1;
        for(int i=n-1;i>=0;i-=1){
            for(int l=-sum;l<=sum;l+=1){
                if(l+nums[i]<=sum && l+nums[i]>=-sum)
                    dp[i%2][l+sum]=dp[(i+1)%2][l+nums[i]+sum];
                if(l-nums[i]<=sum && l-nums[i]>=-sum)
                    dp[i%2][l+sum]+=dp[(i+1)%2][l-nums[i]+sum];
            }
        }
        return dp[0][S+sum];
    }
};