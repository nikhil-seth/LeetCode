// 1334. Find the City With the Smallest Number of Neighbors at a Threshold Distance
class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold){
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        vector<vector<int>> dp(n,vector<int>(n,10001));
        for(auto x:edges)
            dp[x[0]][x[1]]=dp[x[1]][x[0]]=x[2];
        for(int i=0;i<n;i+=1)
            dp[i][i]=0;
        for(int k=0;k<n;k+=1){
            for(int i=0;i<n;i+=1){
                for(int j=0;j<n;j+=1)
                    dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
            }
        }
        int mval=n+1,ctr,ans=n;
        for(int i=n-1;i>=0;i-=1){
            ctr=0;
            for(int j=0;j<n;j+=1){
                if(dp[i][j]<=distanceThreshold)
                    ctr+=1;
            }
            if(ctr<mval)
                ans=i,mval=ctr;
        }
        return ans;
    }
};
