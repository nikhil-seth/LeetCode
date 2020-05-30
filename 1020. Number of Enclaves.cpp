// 1020. Number of Enclaves
class Solution {
public:
    int n,m,x,y;
    int d[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
    void dfs(vector<vector<int>> &A,int i,int j){
        A[i][j]=0;
        for(auto v:d){
            x=i+v[0],y=j+v[1];
            if(x<n && x>=0 && y<m && y>=0 && A[x][y]==1)
                dfs(A,x,y);
        }
    }
    int numEnclaves(vector<vector<int>>& A){
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        if(!A.size() || !A[0].size()) return 0;
        int ctr=0;
        n=A.size(),m=A[0].size();
        for(int i=0;i<n;i+=1){
            if(A[i][0])
                dfs(A,i,0);
            if(A[i][m-1])
                dfs(A,i,m-1);   
        }
        for(int i=0;i<m;i+=1){
            if(A[0][i])
                dfs(A,0,i);
            if(A[n-1][i])
                dfs(A,n-1,i);
        }
        for(int i=1;i<n-1;i+=1){
            for(int j=1;j<m-1;j+=1){
                if(A[i][j])
                    ctr+=1;
            }
        }
        return ctr;
    }
};