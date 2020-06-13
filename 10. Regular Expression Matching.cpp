// 10. Regular Expression Matching

class Solution {
public:
    bool isMatch(string s, string p){
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        int n=s.length(),m=p.length();
        bool dp[n+1][m+1];
        memset(dp,0,sizeof(dp));
        /*
        Base Case - i=0,j=0->1
        */
        dp[0][0]=1;
        for(int j=2;j<=m;j+=1){
            if(p[j-1]=='*')
                dp[0][j]=dp[0][j-2];
        }
        for(int i=1;i<=n;i+=1){
            for(int j=1;j<=m;j+=1){
                if(p[j-1]=='.' || p[j-1]==s[i-1])
                    dp[i][j]=dp[i-1][j-1];
                else if(p[j-1]=='*'){
                    dp[i][j]=dp[i][j-2];
                    if(p[j-2]=='.' || s[i-1]==p[j-2])
                        dp[i][j]=dp[i][j] || dp[i][j-1] || dp[i-1][j];
                }
            }
        }
        // for(int i=0;i<=n;i+=1){
         //   for(int j=0;j<=m;j+=1)
           //     cout<<dp[i][j]<<' ';
        //    cout<<endl;
        //}
        return dp[n][m];
    }
};