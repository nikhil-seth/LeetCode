// 200. Number of Islands

class Solution {
public:
    void dfs(vector<vector<char>>& grid,vector<vector<bool>> &vis,int i,int j,int n,int m){
        if(vis[i][j]==1 || grid[i][j]=='0')
            return;
        vis[i][j]=1;
        if(i<n-1)
            dfs(grid,vis,i+1,j,n,m);
        if(j<m-1)
            dfs(grid,vis,i,j+1,n,m);
        if(i>0)
            dfs(grid,vis,i-1,j,n,m);
        if(j>0)
            dfs(grid,vis,i,j-1,n,m);
    }
    int numIslands(vector<vector<char>>& grid){
        int n=grid.size();
        if(n==0)
            return 0;
        int ans=0;
        int m=grid[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]==0 && grid[i][j]=='1'){
                    //cout<<i<<' '<<j<<endl;
                    dfs(grid,vis,i,j,n,m);
                    ans+=1;
                }
            }
        }
        return ans;
    }
};