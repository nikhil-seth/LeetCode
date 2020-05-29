// 210. Course Schedule II

class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& edge){
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        vector<int> emp,ans,ind(n);
        vector<vector<int>> adj(n);
        
        queue<int> q;
        for(auto x:edge){
            adj[x[1]].push_back(x[0]);
            ind[x[0]]+=1;
        }
        for(int i=0;i<n;i+=1){
            if(ind[i]==0)
                q.push(i);
        }
        
        int i=0,x;
        while(!q.empty()){
            x=q.front();
            q.pop();
            ans.push_back(x);
            for(auto v:adj[x]){
                ind[v]--;
                if(ind[v]==0)
                    q.push(v);
            }
        }
        if(ans.size()==n)
            return ans;
        return emp;
    }
};
