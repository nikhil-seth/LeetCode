//322. Coin Change
class Solution {
public:
    int coinChange(vector<int>& coins, int n){
        if(n ==0)
            return 0;
        vector<int> dp(n+1);
        fill(dp.begin(),dp.end(),n+1);
        dp[0]=0;
        for(int i=0;i<coins.size();i++){
            for(int j=coins[i];j<=n;j+=1){
                if(dp[j-coins[i]]!=n+1)
                    dp[j]=(dp[j]==-1)?dp[j-coins[i]]+1:min(dp[j],dp[j-coins[i]]+1);
            }
        }
        if(dp[n]==n+1)
            return -1;
        return dp[n];
    }
};