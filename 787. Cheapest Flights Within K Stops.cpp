// 787. Cheapest Flights Within K Stops

#define ti tuple<int,int,int> 
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& F, int src, int dst, int K){
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        vector<vector<pair<int,long>>> adj(n);
        for(auto &x:F){
            adj[x[0]].push_back({x[1],x[2]});
        }
        priority_queue<ti,vector<ti>,greater<ti>> pq;
        pq.push({0,src,K+1});
        while(!pq.empty()){
            auto [a,b,c]=pq.top();
            pq.pop();
            if(b==dst) return a;
            if(!c) continue;
            for(auto &x:adj[b]){
                pq.push({x.second+a,x.first,c-1});
            }
        }
        return -1;
    }
};
