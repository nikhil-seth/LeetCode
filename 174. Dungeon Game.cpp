// 174. Dungeon Game
static auto io=[](){ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);return 0;}();
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& arr){
        if(!arr.size() || !arr[0].size()) return 1;
        int n=arr.size(),m=arr[0].size();
        int dp[n+1][m+1];
        for(int i=0;i<=n;i+=1)
            dp[i][m]=INT_MAX;
        for(int i=0;i<=m;i+=1)
            dp[n][i]=INT_MAX;
        dp[n-1][m]=dp[n][m-1]=1;
        for(int i=n-1;i>=0;i-=1){
            for(int j=m-1;j>=0;j-=1){
                dp[i][j]=min(dp[i+1][j],dp[i][j+1])-arr[i][j];
                if(dp[i][j]<=0)
                    dp[i][j]=1;
            }
        }
        return dp[0][0];
    }
};
