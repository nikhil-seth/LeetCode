// 59. Spiral Matrix II

class Solution {
public:
    vector<vector<int>> generateMatrix(int n){
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        int x=0,y=-1;
        vector<vector<int>> v(n,vector<int>(n));
        int m=n;
        int ctr=1;
        int d[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
        int dir=0;
        while(n && m){
            for(int j=0;j<m;j+=1){
                x+=d[dir][0],y+=d[dir][1];
                v[x][y]=ctr++;
            }
            n-=1;
            swap(n,m);
            dir=(dir+1)%4;
        }
        return v;
    }
};
