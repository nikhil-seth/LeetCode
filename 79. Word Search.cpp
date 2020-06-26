// 79. Word Search

class Solution {
public:
    int d[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
    bool bt(vector<vector<char>> &b,string &word,int i,int x,int y){
        if(i==word.size()) return 1;
        if(x<0 || y<0 || x>=b.size() || y>=b[0].size()) return 0;

        if(b[x][y]=='#' || b[x][y]!=word[i]) return 0;
        char temp=b[x][y];
        b[x][y]='#';
        bool ans=0;
        int a,bx;
        for(auto &v:d){
            if(ans) break;
            a=x+v[0],bx=y+v[1];
            ans=ans||(bt(b,word,i+1,a,bx));
        }
        b[x][y]=temp;
        return ans;
    }
    bool exist(vector<vector<char>>& board, string word){
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        for(int i=0;i<board.size();i+=1){
            for(int j=0;j<board[0].size();j+=1){
                if(bt(board,word,0,i,j)){
                    return 1;
                }
            }
        }
        return 0;
    }
};
