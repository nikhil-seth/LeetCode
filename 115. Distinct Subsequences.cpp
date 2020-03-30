//115. Distinct Subsequences
class Solution {
public:
    int numDistinct(string s, string t) {
        int n=s.length();
        int m=t.length();
        if(n==0)
            return 0;
        if(m==0)
            return 1;
        long long dp[2][m+1];
        memset(dp,0,sizeof(dp));
        dp[0][0]=1;
        for(int i=1;i<=n;i++){
            for(int j=0;j<=m;j++){
                if(j==0)
                    dp[i%2][j]=1;
                else{
                    dp[i%2][j]=dp[(i+1)%2][j];
                    if(s[i-1]==t[j-1])
                        dp[i%2][j]+=dp[(i+1)%2][j-1];
                }
            }
        }
        return dp[n%2][m];
    }
};