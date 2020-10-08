// 10. Regular Expression Matching

class Solution {
public:
bool isMatch(string s, string p){
	int n=s.length(),m=p.length();
    bool dp[2][m+1];
    memset(dp,0,sizeof(dp));
    
	//vector<vector<bool>> dp(2,vector<bool>(m+1,0));
	dp[0][0]=1;
	for(int j=2;j<=m;j+=1){
		if(p[j-1]=='*')
			dp[0][j]=dp[0][j-2];
	}
	for(int i=1;i<=n;i+=1){
        dp[i%2][0]=0;
		for(int j=1;j<=m;j+=1){
			if(p[j-1]=='.' || s[i-1]==p[j-1])
				dp[i%2][j]=dp[(i-1)%2][j-1];
			else if(p[j-1]=='*' && j>1){
				dp[i%2][j]=dp[i%2][j-2];
				if(p[j-2]=='.' || s[i-1]==p[j-2])
                    			dp[i%2][j]=dp[i%2][j] || (dp[(i-1)%2][j]);
		        }
			else
				dp[i%2][j]=0;
            //cout<<dp[i%2][j]<<' ';
		
        }
        //cout<<endl;
        }
	return dp[n%2][m];
}
};
