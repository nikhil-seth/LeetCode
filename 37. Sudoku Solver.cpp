// 37. Sudoku Solver

class Solution {
public:
    bool row[9][10];
    bool col[9][10];
    bool grp[9][10];
    bool chk(int i,int j,int k){
        if(row[i][k]==1) return 0;
        if(col[j][k]==1) return 0;
        if(grp[(i/3)*3+j/3][k]==1) return 0;
        return 1;
    }
    bool bt(vector<vector<char>> &board,int ctr){
        if(ctr==81) return 1;
        int i=ctr/9,j=ctr%9;
        if(board[i][j]!='.') return bt(board,ctr+1);
        for(int k=1;k<=9;k+=1){
            if(chk(i,j,k)){
                row[i][k]=1;
                col[j][k]=1;
                grp[(i/3)*3+j/3][k]=1;
                board[i][j]=k+48;
                if(bt(board,ctr+1)) return 1;
                row[i][k]=0;
                col[j][k]=0;
                grp[(i/3)*3+j/3][k]=0;
            }
        }
        board[i][j]='.';
        return 0;
    }
    void solveSudoku(vector<vector<char>>& board){
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        memset(row,0,sizeof(row));
        memset(col,0,sizeof(row));
        memset(grp,0,sizeof(row));
        for(int i=0;i<9;i+=1){
            for(int j=0;j<9;j+=1){
                if(board[i][j]!='.'){
                    row[i][board[i][j]-48]=1;
                    col[j][board[i][j]-48]=1;
                    grp[(i/3)*3+j/3][board[i][j]-48]=1;
                }
            }
        }
        bt(board,0);
    }
};