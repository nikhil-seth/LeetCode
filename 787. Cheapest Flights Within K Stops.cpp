// 787. Cheapest Flights Within K Stops

#define pii pair<int,int>
#define ti tuple<int,int,int>
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K){
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        vector<pii> adj[n];
        for(auto x:flights)
            adj[x[0]].push_back({x[1],x[2]});
        priority_queue<ti,vector<ti>,greater<ti>> pq;
        pq.emplace(0,src,K+1);
        while(!pq.empty()){
            auto [dist,u,stop]=pq.top();
            pq.pop();
            if(u==dst)
                return dist;
            if(!stop) continue;
            for(auto x:adj[u])
                pq.emplace(x.second+dist,x.first,stop-1);
        }
        return -1;
    }
};
