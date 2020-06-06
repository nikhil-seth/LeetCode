// 417. Pacific Atlantic Water Flow

class Solution {
public:
    int d[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
    int n,m,x,y;
    void dfs(vector<vector<int>> &matrix,vector<vector<bool>> &b,int i,int j){
        b[i][j]=1;
        for(auto v:d){
            x=i+v[0],y=j+v[1];
            if(x>=0 && y>=0 && x<n && y<m && b[x][y]==0 && matrix[i][j]<=matrix[x][y]) 
                dfs(matrix,b,x,y);
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix){
        vector<vector<int>> ans;
        vector<int> vx(2);
        if(!matrix.size() || !matrix[0].size()) return ans;
        n=matrix.size(),m=matrix[0].size();
        vector<vector<bool>> b1(n,vector<bool>(m,0));
        vector<vector<bool>> b2(n,vector<bool>(m,0));
        for(int i=0;i<n;i+=1){
            dfs(matrix,b1,i,0);
            dfs(matrix,b2,i,m-1);
        }
        for(int i=0;i<m;i+=1){
            dfs(matrix,b1,0,i);
            dfs(matrix,b2,n-1,i);
        }
        for(int i=0;i<n;i+=1){
            for(int j=0;j<m;j+=1){
                if(b1[i][j] && b2[i][j]){
                    vx[0]=i,vx[1]=j;
                    ans.push_back(vx);
                }
            }
        }
        return ans;
    }
};
