// 310. Minimum Height Trees

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges){
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        vector<int> ans;
        if(n==0) return ans;
        if(n==1){
            ans.push_back(0);
            return ans;
        }
        vector<int> adj[n];
        vector<int> c(n,0);
        int ctr=n-1;
        for(auto x:edges){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
            c[x[0]]+=1;
            c[x[1]]+=1;
        }
        queue<int> q;
        for(int i=0;i<n;i+=1){
            if(c[i]==1)
                q.push(i);
        }
        // We put leaf nodes.
        while(ctr>1){
            int x,len=q.size();
            while(len--){
                x=q.front();
                q.pop();
                for(auto v:adj[x]){
                    c[v]-=1;
                    if(c[v]>=1)
                        ctr-=1;
                    if(c[v]==1) q.push(v);
                }
            }
        }
        while(!q.empty()){
            ans.push_back(q.front());
            q.pop();
        }
        return ans;
    }
};

