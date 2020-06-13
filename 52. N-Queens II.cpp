// 52. N-Queens II

class Solution {
public:
    bool **grid;
    int n,ans=0;
    bool chk(int x,int y){
        for(int i=0;i<x;i+=1){
            if(grid[i][y]) return 0;
        }
        for(int i=x,j=y;i>=0 && j>=0;i-=1,j-=1){
            if(grid[i][j]) return 0;
        }
        for(int i=x,j=y;i>=0 && j<n;i-=1,j+=1){
            if(grid[i][j]) return 0;
        }
        return 1;
    }
    void bt(int i){
        if(i==n) ans+=1;
        else{
            for(int j=0;j<n;j+=1){
                if(chk(i,j)){
                    grid[i][j]=1;
                    bt(i+1);
                    grid[i][j]=0;
                }
            }
        }
    }
    int totalNQueens(int n){
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        this->n=n;
        grid=new bool*[n];
        for(int i=0;i<n;i+=1){
            grid[i]=new bool[n];
            for(int j=0;j<n;j+=1)
                grid[i][j]=0;
        }
        bt(0);
        return ans;
    }
};