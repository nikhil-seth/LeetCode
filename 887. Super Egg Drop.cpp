class Solution {
public:
    int superEggDrop(int k, int N) {
        int dp[2][k+1];
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=N;i++){
            for(int j=1;j<=k;j++){
                dp[i%2][j]=dp[(i+1)%2][j-1] + dp[(i+1)%2][j]+1;
                if(dp[i%2][j]>=N)
                    return i;
            }
        }
        return N;
    }
};