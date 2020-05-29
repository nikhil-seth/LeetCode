// 207. Course Schedule
class Solution {
    vector<int> vis;
    vector<vector<int>> adj;
public:
    bool dfs(int u){
        vis[u]=1;
        for(auto v:adj[u]){
            if(vis[v]==0){
                if(!dfs(v))
                    return 0;
            }
            else if(vis[v]==1)
                return 0;
        }
        vis[u]=2;
        return 1;
    }
    bool canFinish(int n, vector<vector<int>>& prerequisites){
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        vis=vector<int>(n,0);
        adj=vector<vector<int>>(n);
        for(auto x:prerequisites){
            adj[x[1]].push_back(x[0]);
        }
        for(int i=0;i<n;i+=1){
            if(vis[i]==0){
                if(!dfs(i))
                    return 0;
            }
        }
        return 1;
    }
};
