// 959. Regions Cut By Slashes

class Solution {
public:
    vector<int> parent;
    int n;
    int dec(int i,int j,int k){
        return i*n*4+j*4+k;
    }
    int find(int v){
        if(parent[v]==v) return v;
        return parent[v]=find(parent[v]);
    }
    void unionset(int u,int v){
        u=find(u);
        v=find(v);
        if(u!=v){
            parent[v]=u;
        }
    }
    int regionsBySlashes(vector<string>& grid){
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        n=grid.size();
        if(!n) return 0;
        parent=vector<int>(4*n*n);
        for(int i=0;i<4*n*n;i+=1)
            parent[i]=i;
        for(int i=0;i<n;i+=1){
            for(int j=0;j<n;j+=1){
                if(i>0) unionset(dec(i,j,0),dec(i-1,j,2));
                if(j>0) unionset(dec(i,j,3),dec(i,j-1,1));
                if(grid[i][j]!='\\'){
                    unionset(dec(i,j,0),dec(i,j,3));
                    unionset(dec(i,j,1),dec(i,j,2));
                }
                if(grid[i][j]!='/'){
                    unionset(dec(i,j,0),dec(i,j,1));
                    unionset(dec(i,j,2),dec(i,j,3));
                }
            }
        }
        int ans=0;
        for(int i=0;i<4*n*n;i+=1)
            ans+=(parent[i]==i)?1:0;
        return ans;
    }
};