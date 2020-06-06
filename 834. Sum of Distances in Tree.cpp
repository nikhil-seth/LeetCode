// 834. Sum of Distances in Tree

class Solution {
public:
    vector<int> ans,count;
    void dfs(vector<vector<int>> &adj,int u,int par,const int &N){
        for(auto v:adj[u]){
            if(v==par) continue;
            dfs(adj,v,u,N);
            count[u]+=count[v];
            ans[u]+=ans[v]+count[v];
        }
    }
    void dfs2(vector<vector<int>> &adj,int u,int par,int &N){
        for(auto v:adj[u]){
            if(v==par) continue;
            ans[v]=ans[u]+N-2*count[v];
            dfs2(adj,v,u,N);
        }
    }
    vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges){
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        ans=vector<int>(N,0);
        count=vector<int>(N,1);
        vector<vector<int>> adj(N);
        for(auto x:edges){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        dfs(adj,0,-1,N);
        dfs2(adj,0,-1,N);
        return ans;
    }
};
