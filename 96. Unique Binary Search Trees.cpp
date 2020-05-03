// 96. Unique Binary Search Trees

class Solution {
public:
    int numTrees(int n) {
        long dp[2][n+1];
        memset(dp,0,sizeof(dp));
        for(int i=0;i<=2*n;i++){
            for(int j=0;j<=min(i,n);j+=1){
                if(j==0 || j==i)
                    dp[i%2][j]=1;
                else
                    dp[i%2][j]=(dp[(i+1)%2][j-1]+dp[(i+1)%2][j]);
            }
        }
        dp[(2*n)%2][n]/=(n+1);
        return dp[(2*n)%2][n];
    }
};