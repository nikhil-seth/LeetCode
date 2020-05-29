// 841. Keys and Rooms
class Solution {
public:
    void dfs(vector<vector<int>> &rooms,vector<bool> &vis,int u){
        vis[u]=1;
        for(auto c:rooms[u]){
            if(!vis[c])
                dfs(rooms,vis,c);
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms){
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        int n=rooms.size();
        vector<bool> vis(n,0);
        dfs(rooms,vis,0);
        for(int i=0;i<n;i+=1){
            if(!vis[i]) return 0;
        }
        return 1;
    }
};
