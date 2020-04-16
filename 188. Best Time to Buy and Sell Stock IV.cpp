// 188. Best Time to Buy and Sell Stock IV

class Solution {
public:
    int maxProfit(int k, vector<int>& prices){
        if(k==0 || prices.size()<2)
            return 0;
        int n=prices.size();
        if(k>=n/2){
           // Max Bnane h 
            int ans=0;
            for(int i=1;i<n;i++){
                ans+=max(prices[i]-prices[i-1],0);
            }
            return ans;
        }
        int dp[2][n];
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=k;i++){
            int prevDiff=INT_MIN;
            for(int j=1;j<n;j++){
                prevDiff=max(prevDiff,dp[(i+1)%2][j-1]-prices[j-1]);
                dp[i%2][j]=max(dp[i%2][j-1],prices[j]+prevDiff);
            }
        }
        return dp[k%2][n-1];
    }
};