// 279. Perfect Squares

class Solution {
public:
    int numSquares(int n){
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        vector<int> ps,dp(n+1,INT_MAX);
        for(int i=1;i*i<=n;i+=1)
            ps.push_back(i*i);
        dp[0]=0;
        for(int i=1;i<=n;i+=1){
            for(int j=1;j*j<=i;j+=1){
                dp[i]=min(dp[i],dp[i-j*j]+1);
            }
        }
        return dp[n];
    }
};
        