// 947. Most Stones Removed with Same Row or Column

class Solution {
public:
    vector<int> parent;
    vector<int> size;
    int findset(int v){
        if(parent[v]==v)
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
            size[v]=0;
        }
    }
    int removeStones(vector<vector<int>>& stones){
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        if(!stones.size()) return 0;
        parent=vector<int>(20000);
        size=vector<int>(20000,1);
        int ans=0;
        for(int i=0;i<20000;i+=1)
            parent[i]=i;
        unordered_set<int> s;
        for(auto &x:stones)
            unionset(x[0],10000+x[1]);
        for(auto &x:stones){
            if(findset(x[0])==x[0])
                s.insert(x[0]);
        }
        return stones.size()-s.size();
    }
};
