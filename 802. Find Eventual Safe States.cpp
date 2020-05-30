// 802. Find Eventual Safe States

class Solution {
public:
    int ctx=0;
    bool dfs(vector<vector<int>> &graph,vector<int> &vis,int u){
        vis[u]=1;
        for(auto x:graph[u]){
            if(vis[x]==0){
                if(!dfs(graph,vis,x)) return 0;
            }
            else if(vis[x]==1)
                return 0;
        }
        vis[u]=2;
        return 1;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph){
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        int n=graph.size();
        vector<int> ans;
        vector<int> vis(n,0);
        for(int i=0;i<n;i+=1){
            if(vis[i]==0)
                dfs(graph,vis,i);
            if(vis[i]==2)
                ans.push_back(i);
        }
        return ans;
    }
};

        