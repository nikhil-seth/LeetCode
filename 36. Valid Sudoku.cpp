// 36. Valid Sudoku
class Solution {
public:
    bool chk(vector<vector<char>> &board,int i,int j){
        int rc=0,cc=0;
        for(int k=0;k<9 && rc<2 && cc<2;k+=1){
            if(board[i][k]==board[i][j])
                cc+=1;
            if(board[k][j]==board[i][j])
                rc+=1;
        }
         if(rc>1 || cc>1) return 0;
        rc=0;
        for(int a=(i/3)*3;a<(i/3)*3+3;a+=1){
            for(int b=(j/3)*3;b<(j/3)*3+3;b+=1){
                if(board[a][b]==board[i][j]) rc+=1;
            }
        }
        if(rc>1)return 0;
        return 1;
    }
    bool isValidSudoku(vector<vector<char>>& board){
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        for(int i=0;i<9;i+=1){
            for(int j=0;j<9;j+=1){
                if(board[i][j]=='.') continue;
                if(!chk(board,i,j)) return 0;
            }
        }
        return 1;
    }
};