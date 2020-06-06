// 329. Longest Increasing Path in a Matrix

class Solution {
public:
    int n,m,ans,x,y;
    vector<vector<int>> dp;
    int d[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
    int dfs(int i,int j,vector<vector<int>> &matrix){
        if(dp[i][j]!=0) return dp[i][j];
        for(auto v:d){
            x=i+v[0],y=j+v[1];
            if(x<n && x>=0 && y<m && y>=0 && matrix[x][y]>matrix[i][j])
                dp[i][j]=max(dp[i][j],dfs(x,y,matrix));
        }
        dp[i][j]+=1;
        return dp[i][j];
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        /* Equal case is not valid.
           We need Increasing, therefore if a->b, b->a.
        */
        if(!matrix.size() || !matrix[0].size()) return 0;
        n=matrix.size(),m=matrix[0].size();
        ans=0;
        dp=vector<vector<int>>(n,vector<int>(m,0));
        for(int i=0;i<n;i+=1){
            for(int j=0;j<m;j+=1){
                if(dp[i][j]==0)
                    dfs(i,j,matrix),ans=max(ans,dp[i][j]);
            }
        }
        return ans;
    }
};
