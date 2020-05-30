// 1254. Number of Closed Islands

class Solution {
public:
    int d[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
    int n,m,x,y;
    void dfs(vector<vector<int>> &grid,int i,int j){
        grid[i][j]=2;
        for(auto v:d){
            x=i+v[0],y=j+v[1];
            if(x<n && x>=0 && y<m && y>=0 && grid[x][y]==0)
                dfs(grid,x,y);
        }
    }
    bool ctrdfs(vector<vector<int>> &grid,int i,int j){
        grid[i][j]=3;
        for(auto v:d){
            x=i+v[0],y=j+v[1];
            if(grid[x][y]==0){
                if(!ctrdfs(grid,x,y)) return 0;
            }
            else if(grid[x][y]==2)
                return 0;
        }
        return 1;
    }
    int closedIsland(vector<vector<int>>& grid){
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        if(!grid.size() || !grid[0].size()) return 0;
        int ctr=0;
        n=grid.size(),m=grid[0].size();
        for(int i=0;i<n;i+=1){
            if(grid[i][0]==0)
                dfs(grid,i,0);
            if(grid[i][m-1]==0)
                dfs(grid,i,m-1);
        }
        for(int i=0;i<m;i+=1){
            if(grid[0][i]==0)
                dfs(grid,0,i);
            if(grid[n-1][i]==0)
                dfs(grid,n-1,i);
        }
        for(int i=1;i<n-1;i+=1){
            for(int j=1;j<m-1;j+=1){
                if(grid[i][j]==0)
                    ctr+=ctrdfs(grid,i,j);
            }
        }
        return ctr;
    }
};
