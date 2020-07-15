// 1345. Jump Game IV
class Solution {
public:
    int minJumps(vector<int>& arr){
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        unordered_map<int,vector<int>> m;
        int n=arr.size();
        for(int i=n-1;i>=0;i-=1){
            m[arr[i]].push_back(i);
        }
        vector<bool> vis(n,0);
        queue<int> q;
        q.push(0);
        int ans=0,len;
        while(!q.empty()){
            len=q.size();
            while(len--){
                int x=q.front();
                q.pop();
                if(x<0 || x>=n || vis[x]) continue;
                if(x==n-1) return ans;
                vis[x]=1;
                q.push(x-1),q.push(x+1);
                for(auto y:m[arr[x]]){
                    if(vis[y]) continue;
                    else q.push(y);
                }
                m[arr[x]].clear();
            }
            ans+=1;
        }
        return ans;
    }
};

        