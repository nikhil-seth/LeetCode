// 1042. Flower Planting With No Adjacent
class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths){
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        vector<vector<int>> adj(n+1);
        vector<int> color(n+1,0);
        for(auto x:paths)
            adj[x[0]].push_back(x[1]),adj[x[1]].push_back(x[0]);
        for(int i=1;i<=n;i+=1){
            vector<bool> b(5,0);
            for(auto &v:adj[i])
                if(color[v]) b[color[v]]=1;
            for(int idx=1;idx<=4;idx+=1){
                if(b[idx]) continue;
                color[i]=idx;
                b[idx]=1;
                break;
            }
        }
        color.erase(color.begin(),color.begin()+1);
        return color;
    }
};