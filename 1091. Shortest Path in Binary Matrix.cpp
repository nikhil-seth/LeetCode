// 1091. Shortest Path in Binary Matrix

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid){
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        int n=grid.size();
        if(!n || grid[n-1][n-1]==1) return -1;
        queue<pair<int,int>> q;
        int d[8][2]={{1,0},{-1,0},{0,1},{0,-1},{1,1},{-1,-1},{1,-1},{-1,1}};
        int i,ctr=1,j,x,y,len;
        q.push({0,0});
        while(!q.empty()){
            len=q.size();
            while(len--){
                i=q.front().first;
                j=q.front().second;
                q.pop();
                if(grid[i][j]==1) continue;
                if(i==n-1 && j==n-1) return ctr;
                grid[i][j]=1;
                for(auto &v:d){
                    x=i+v[0],y=j+v[1];
                    if(x<0 || x>=n || y<0 || y>=n || grid[x][y]==1)
                        continue;
                    q.push({x,y});
                }
            }
            ctr+=1;
        }
        return -1;
    }
};
