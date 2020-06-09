// 1466. Reorder Routes to Make All Paths Lead to the City Zero
class Solution {
public:
    int ctr=0;
    void dfs(vector<vector<pair<int,bool>>> &adj,int v,int par){
        for(auto x:adj[v]){
            if(x.first==par) continue;
            if(x.second==0) ctr+=1;
            dfs(adj,x.first,v);
        }
    }
    int minReorder(int n, vector<vector<int>>& connections){
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        vector<vector<pair<int,bool>>> adj(n);
        for(auto x:connections){
            adj[x[1]].push_back({x[0],1});
            adj[x[0]].push_back({x[1],0});
        }
        dfs(adj,0,-1);
        return ctr;
    }
};