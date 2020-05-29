// 1267. Count Servers that Communicate
class Solution {
public:
    int countServers(vector<vector<int>>& grid){
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        int n=grid.size(),m=grid[0].size();
        vector<int> r(n,0),c(m,0);
        int ctr=0;
        for(int i=0;i<n;i+=1){
            for(int j=0;j<m;j+=1){
                if(grid[i][j]==1)
                    r[i]+=1,c[j]+=1;
            }
        }
        for(int i=0;i<n;i+=1){
            for(int j=0;j<m;j+=1){
                if(grid[i][j]==1 && (r[i]>1 || c[j]>1))
                   ctr+=1;
            }
        }
        return ctr;
    }
};
