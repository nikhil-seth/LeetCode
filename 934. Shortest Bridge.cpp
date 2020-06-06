// 934. Shortest Bridge
class Solution {
public:
    queue<pair<int,int>> q;
    int n,m,x,y;
    int d[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
    void conv(vector<vector<int>> &A,int i,int j){
        A[i][j]=2;
        for(auto v:d){
            x=i+v[0],y=j+v[1];
            if(x>=0 && y>=0 && x<n && y<m){
                if(A[x][y]==1)
                    conv(A,x,y);
                else
                    q.push({x,y});
            }
        }
    }
    int shortestBridge(vector<vector<int>>& A){
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        n=A.size(),m=A[0].size();
        bool f=0;
        for(int i=0;i<n;i+=1){
            for(int j=0;j<m;j+=1){
                if(A[i][j]==1){
                    conv(A,i,j);
                    f=1;
                    break;
                }
            }
            if(f) break;
        }
        int ctr=0,len;
        int i,j;
        while(!q.empty()){
            len=q.size();
            while(len--){
                i=q.front().first;
                j=q.front().second;
                //cout<<i<<' '<<j<<endl;
                q.pop();
                if(A[i][j]==2) continue;
                if(A[i][j]==1) return ctr;
                A[i][j]=2;
                for(auto v:d){
                    x=i+v[0],y=j+v[1];
                    if(x>=0 && y>=0 && x<n && y<m && A[x][y]!=2)
                        q.push({x,y});
                    }
            }
            ctr+=1;
        }
        return ctr;
    }
};
