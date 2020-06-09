// 1443. Minimum Time to Collect All Apples in a Tree

class Solution {
public:
    int ans=0;
    bool dfs(vector<vector<int>> &adj,vector<bool> & hasApple,int v,int par){
        bool has=hasApple[v];
        for(auto x:adj[v]){
            if(par==x) continue;
            has|=dfs(adj,hasApple,x,v);
        }
        if(has) ans+=2;
        return has;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> adj(n);
        for(auto x:edges){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        for(auto x:adj[0]){
            dfs(adj,hasApple,x,0);
        }
        return ans;
    }
};
