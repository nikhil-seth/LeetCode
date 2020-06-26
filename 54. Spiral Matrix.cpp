// 54. Spiral Matrix

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        vector<int> ans;
        int n=matrix.size();
        if(!n) return ans;
        int m=matrix[0].size();
        int d[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
        int x=0,y=-1;
        int dir=0;
        while(m && n){
            for(int j=0;j<m;j+=1){
                x+=d[dir][0],y+=d[dir][1];
                ans.push_back(matrix[x][y]);
                //cout<<j<<' ';
            }
           // cout<<endl;
            n-=1;
            swap(n,m);
            dir=(dir+1)%4;
        }
        return ans;
    }
};