// 695. Max Area of Island
class Solution {
public:
    int n,m,x,y;
    int ans;
    int d[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
    void bfs(vector<vector<int>> &grid,int i,int j){
        queue<pair<int,int>> q;
        q.push({i,j});
        int val=1;
        while(!q.empty()){
            i=q.front().first;
            j=q.front().second;
            q.pop();
            for(auto v:d){
                x=i+v[0],y=j+v[1];
                if(x<n && x>=0 && y<m && y>=0 && grid[x][y]==1)
                    grid[x][y]=0,q.push({x,y}),val+=1;
            }
        }
        ans=max(ans,val);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid){
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        if(!grid.size() || !grid[0].size()) return 0;
        n=grid.size(),m=grid[0].size(),ans=0;
        for(int i=0;i<n;i+=1){
            for(int j=0;j<m;j+=1){
                if(grid[i][j]==1){
                    grid[i][j]=0,bfs(grid,i,j);
                }
            }
        }
        return ans;
    }
};