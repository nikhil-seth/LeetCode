// 1035. Uncrossed Lines

class Solution {
public:
    int maxUncrossedLines(vector<int>& A, vector<int>& B){
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        int n=A.size(),m=B.size(),ans=0;
        if(!n || !m) return 0;
        int dp[n+1][m+1];
        memset(dp,0,sizeof(dp));
        for(int i=n-1;i>=0;i-=1){
            for(int j=m-1;j>=0;j-=1){
                if(A[i]==B[j])
                    dp[i][j]=1+dp[i+1][j+1];
                else
                    dp[i][j]=max(dp[i+1][j],dp[i][j+1]);
                ans=max(ans,dp[i][j]);
            }
        }
        return ans;
    }
};
