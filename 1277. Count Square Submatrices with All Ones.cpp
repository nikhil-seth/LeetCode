// 1277. Count Square Submatrices with All Ones

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int count=0;
        
        int dp[n+1][m+1];
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                if(i==0 || j==0)
                dp[i][j]=0;
                else if(matrix[i-1][j-1]==1) 
                   {dp[i][j]=min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]))+1;
                count+=dp[i][j];}
                else
                    dp[i][j]=0;
            }
        }

        return count;
    }
};