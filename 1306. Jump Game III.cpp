// 1306. Jump Game III

class Solution {
public:
    bool canReach(vector<int>& arr, int start){
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        int n=arr.size();
        vector<bool> vis(n,0);
        vis[start]=1;
        queue<int> q;
        q.push(start);
        while(!q.empty()){
            start=q.front();
            if(arr[start]==0)
                return 1;
            q.pop();
            if(start+arr[start]<n && !vis[start+arr[start]]){
                vis[start+arr[start]]=1;
                q.push(start+arr[start]);
            }
            if(start-arr[start]>=0 && !vis[start-arr[start]]){
                vis[start-arr[start]]=1;
                q.push(start-arr[start]);
            }
        }
        return 0;
    }
};
