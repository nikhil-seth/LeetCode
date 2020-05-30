// 785. Is Graph Bipartite?

class Solution {
public:
    vector<int> vis;
    bool dfs(vector<vector<int>> &adj,int u,int c){
        if(vis[u]!=0)
            return vis[u]==c;
        vis[u]=c;
        for(auto v:adj[u]){
            if(!dfs(adj,v,-c))
                return 0;
        }
        return 1;
    }
    bool isBipartite(vector<vector<int>>& adj){
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        int n=adj.size();
        vis=vector<int>(n,0);
        for(int i=0;i<n;i+=1){
            if(vis[i]==0){
                if(!dfs(adj,i,1)) return 0;
            }
        }
        return 1;
    }
};