// 851. Loud and Rich

class Solution {
public:
    vector<vector<int>> adj;
    vector<int> ans;
    void dfs(int v,vector<bool> &vis,vector<int> &quiet){
        vis[v]=1;
        ans[v]=v;
        for(auto &x:adj[v]){
            if(!vis[x])
                dfs(x,vis,quiet);
            if(quiet[ans[x]]<quiet[ans[v]])
                ans[v]=ans[x];
        }
    }
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet){
         ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
       int n=quiet.size();
        adj=vector<vector<int>>(n);
        for(auto x:richer)
            adj[x[1]].push_back(x[0]);
        vector<bool> vis(n,0);
        ans=vector<int>(n,0);
        for(int i=0;i<n;i+=1){
            if(!vis[i])
                dfs(i,vis,quiet);
        }
        return ans;
    }
};
