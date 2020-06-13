// 51. N-Queens

class Solution {
public:
    vector<vector<string>> ans;
    vector<string> grid;
    int n;
    bool chk(int x,int y){
        // Check for Col.
        for(int i=0;i<n;i+=1){
            if(grid[i][y]=='Q') return 0;
        }
        // Below 2 for loops for diagonal 
        for(int i=x,j=y;i>=0 && j>=0;i-=1,j-=1){
            if(grid[i][j]=='Q') return 0;
        }
        for(int i=x,j=y;i<n && j<n;i+=1,j+=1){
            if(grid[i][j]=='Q') return 0;
        }
        // For diagonal /
        for(int i=x,j=y;i>=0 && j<n;i-=1,j+=1){
            if(grid[i][j]=='Q') return 0;
        }
        for(int i=x,j=y;i<n && j>=0;i+=1,j-=1){
            if(grid[i][j]=='Q') return 0;
        }
        return 1;
    }
    void bt(int i){
        if(i==n) ans.push_back(grid);
        for(int j=0;j<n;j+=1){
            if(chk(i,j)){
                grid[i][j]='Q';
                bt(i+1);
                grid[i][j]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n){
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        string s;
        this->n=n;
        for(int i=0;i<n;i+=1)
            s.push_back('.');
        grid=vector<string>(n,s);
        bt(0);
        return ans;
    }
};
