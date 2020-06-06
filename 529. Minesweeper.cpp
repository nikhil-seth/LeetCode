// 529. Minesweeper

class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click){
                ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

        int n=board.size(),m=board[0].size();
        int x=click[0],y=click[1];
        if(board[x][y]=='M'){
            board[x][y]='X';
            return board;
        }
        int ctr,i,j;
        int d[8][2]={{1,0},{-1,0},{0,1},{0,-1},{1,1},{-1,-1},{1,-1},{-1,1}};
        queue<pair<int,int>> q;
        q.push({x,y});
        while(!q.empty()){
            x=q.front().first;
            y=q.front().second;
           // cout<<x<<' '<<y<<endl;
            q.pop();
            if(board[x][y]!='E') continue;
            ctr=0;
            for(auto v:d){
                i=x+v[0],j=y+v[1];
                if(i<n && i>=0 && j<m && j>=0){
                    if(board[i][j]=='M' || board[i][j]=='X')
                        ctr+=1;
                }
            }
            if(ctr==0){
                board[x][y]='B';
                for(auto v:d){
                    i=x+v[0],j=y+v[1];
                    if(i<n && i>=0 && j<m && j>=0 && board[i][j]=='E')
                        q.push({i,j});
                }
            }
            else
                board[x][y]=48+ctr;
        }
        return board;
    }
};
