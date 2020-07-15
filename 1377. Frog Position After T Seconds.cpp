// 1377. Frog Position After T Seconds

class Solution {
public:
    void dfs(vector<vector<int>> &adj,vector<int> &pr,int i,int target,int t,int par){
        pr[i]*=pr[par];
        //cout<<i<<' '<<pr[i]<<endl;
        if(i==target){
            if(t && adj[target].size()>1) pr[i]=0;
            return;
        }
        if(!t) return;
        for(auto &x:adj[i]){
            if(x==par) continue;
            pr[x]=adj[i].size()-1;
            dfs(adj,pr,x,target,t-1,i);
        }
    }
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target){
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        vector<vector<int>> adj(n+1);
        for(auto &x:edges)
            adj[x[0]].push_back(x[1]),adj[x[1]].push_back(x[0]);
        adj[1].push_back(0);
        vector<int> pr(n+1,0);
        pr[0]=pr[1]=1;
        dfs(adj,pr,1,target,t,0);
        if(pr[target]==0) return 0;
        return (double(1)/pr[target]);
    }
};
