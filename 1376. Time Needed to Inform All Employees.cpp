// 1376. Time Needed to Inform All Employees

class Solution {
public:
    int dfs(vector<vector<int>> &adj,vector<int> &informTime,int v){
        if(adj[v].size()==0) return 0;
        int vx=0;
        for(auto u:adj[v]){
            //cout<<v<<' '<<u<<endl;
            vx=max(vx,dfs(adj,informTime,u));
        }
        return vx+informTime[v];
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime){
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        vector<vector<int>> adj(n);
        for(int i=0;i<n;i+=1){
            if(headID==i) continue;
            adj[manager[i]].push_back(i);
        }
        return dfs(adj,informTime,headID);
    }
};
