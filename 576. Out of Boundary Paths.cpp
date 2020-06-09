// 576. Out of Boundary Paths
class Solution {
public:
    int M=1000000007;
    int findPaths(int m, int n, int N, int va, int vb){
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        if(N==0) return 0;
        int val,x,y;
        int d[4][2]={{1,0},{-1,0},{0,-1},{0,1}};
        int st[m][n];
        long long dp[2][m][n];
        memset(st,0,sizeof(st));
        for(int i=0;i<m;i+=1){
            for(int j=0;j<n;j+=1){
                for(auto v:d){
                    x=i+v[0],y=j+v[1];
                    if(x<0 || x>=m || y<0 || y>=n)
                        st[i][j]+=1;
                }
                dp[1][i][j]=st[i][j];
            }
        }
        for(int k=2;k<=N;k+=1){
            for(int i=0;i<m;i+=1){
                for(int j=0;j<n;j+=1){
                    dp[k%2][i][j]=st[i][j];
                    for(auto v:d){
                        x=i+v[0],y=j+v[1];
                        if(x<0 || x>=m || y<0 || y>=n) continue;
                        dp[k%2][i][j]+=dp[(k+1)%2][x][y];
                        dp[k%2][i][j]%=M;
                    }
                }
            }
        }
        return dp[N%2][va][vb];
    }
};
