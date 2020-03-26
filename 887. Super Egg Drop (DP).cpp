class Solution {
public:
    int superEggDrop(int k, int N) {
        int dp[2][N+1],res;
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=N;i++){
            dp[1][i]=i;
        }
        for(int i=2;i<=k;i++){
            for(int j=0;j<=N;j++){
                if(j==0 || j==1)
                    dp[i%2][j]=j;
                else{
                    dp[i%2][j]=INT_MAX;
                    for(int l=1;l<=j;l++){
                        res=1+max(dp[i%2][j-l],dp[(i+1)%2][l-1]);
                        dp[i%2][j]=min(dp[i%2][j],res);
                    }
                }
            }
        }
        return dp[k%2][N];
    }
};
        