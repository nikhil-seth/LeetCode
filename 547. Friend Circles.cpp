// 547. Friend Circles

class Solution {
public:
    vector<int> parent,size;
    int findset(int v){
        if(v==parent[v])
            return v;
        return parent[v]=findset(parent[v]);
    }
    void unionset(int u,int v){
        u=findset(u);
        v=findset(v);
        if(u!=v){
            if(size[u]<size[v])
                swap(u,v);
            parent[v]=u;
            size[u]+=size[v];
        }
    }
    int findCircleNum(vector<vector<int>>& M){
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        int n=M.size();
        parent=vector<int>(n);
        size=vector<int>(n,1);
        for(int i=0;i<n;i+=1)
            parent[i]=i;
        for(int i=0;i<n;i+=1){
            for(int j=i+1;j<n;j+=1){
                if(M[i][j])
                    unionset(i,j);
            }
        }
        int ctr=0;
        for(int i=0;i<n;i+=1)
            ctr+=(parent[i]==i?1:0);
        return ctr;
    }
};
