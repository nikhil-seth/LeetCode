// 130. Surrounded Regions

class Solution {
public:
    int d[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
    int n,m;
    void dfs(vector<vector<char>>& board,int i,int j){
        board[i][j]='1';
        for(int x=0;x<4;x+=1){
            if(i+d[x][0]<n && i+d[x][0]>=0 && j+d[x][1]<m && j+d[x][1]>=0 && board[i+d[x][0]][j+d[x][1]]=='O'){
               // cout<<i<<' '<<j<<"->"<<i+d[x][0]<<' '<<j+d[x]
                dfs(board,i+d[x][0],j+d[x][1]);
            }
        }
    }
    void solve(vector<vector<char>>& board){
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        if(!board.size() || !board[0].size()) return;
        n=board.size();
        m=board[0].size();
        for(int i=0;i<n;i+=1){
            if(board[i][0]=='O')
                dfs(board,i,0);
            if(board[i][m-1]=='O')
                dfs(board,i,m-1);
        }
        for(int i=0;i<m;i+=1){
            if(board[0][i]=='O')
                dfs(board,0,i);
            if(board[n-1][i]=='O')
                dfs(board,n-1,i);
        }
        for(int i=0;i<n;i+=1){
            for(int j=0;j<m;j+=1){
                if(board[i][j]=='O')
                    board[i][j]='X';
                else if(board[i][j]=='1')
                    board[i][j]='O';
            }
        }
    }
};
