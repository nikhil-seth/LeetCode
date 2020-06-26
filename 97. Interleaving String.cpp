// 97. Interleaving String

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3){
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        int n=s1.length(),m=s2.length(),p=s3.length();
        if(p!=n+m) return 0;
        bool dp[n+1][m+1];
        memset(dp,0,sizeof(dp));
        dp[0][0]=1;
        for(int i=1;i<=p;i+=1){
            for(int k=min(m,i),j=i-k;k>=0 && j<=n;k--,j++){
                if(j>0 && s1[j-1]==s3[i-1] && dp[j-1][k])
                    dp[j][k]=1;
                if(k>0 && s2[k-1]==s3[i-1] && dp[j][k-1])
                    dp[j][k]=1;
                //cout<<i<<' '<<j<<' '<<k<<' '<<dp[j][k]<<endl;
            }
        }
        return dp[n][m];
    }
};
