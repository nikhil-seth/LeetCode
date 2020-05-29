// 684. Redundant Connection

class Solution {
public:
    vector<int> parent,size;
    int find(int x){
        if(x==parent[x])
            return x;
        return parent[x]=find(parent[x]);
    }
    void unions(int x,int y){
        if(size[x]<size[y])
            swap(x,y);
        parent[y]=x;
        size[x]+=size[y];
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges){
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        int n=edges.size(),a,b;
        parent=vector<int>(n);
        size=vector<int>(n,1);
        for(int i=0;i<n;i+=1)
            parent[i]=i;
        for(auto x:edges){
            a=find(x[0]-1);
            b=find(x[1]-1);
            if(a==b)
                return x;
            unions(a,b);
        }
        return parent;
    }
};

        