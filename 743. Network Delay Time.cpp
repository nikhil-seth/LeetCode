// 743. Network Delay Time

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K){
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        vector<pair<int,int>> adj[N+1];
        for(auto x:times)
            adj[x[0]].push_back({x[1],x[2]});
        int max_dist=0;
        vector<int> dist(N+1,INT_MAX);
        vector<bool> vis(N+1,0);
        dist[K]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,K});
        while(!pq.empty()){
            K=pq.top().second;
            pq.pop();
            if(vis[K])
                continue;
            vis[K]=1;
            max_dist=max(max_dist,dist[K]);
            for(auto x:adj[K]){
                if(!vis[x.first]){
                    dist[x.first]=min(dist[x.first],dist[K]+x.second);
                    pq.push({dist[x.first],x.first});
                }
            }
        }
        for(int i=1;i<=N;i+=1)
            if(!vis[i]) return -1;
        return max_dist;
    }
};
