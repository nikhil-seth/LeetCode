// 407. Trapping Rain Water II

class Solution {
    struct c{
        int h,i,j;
        c(int a,int b,int c){
            h=a,i=b,j=c;
        }
        bool operator<(const c &cx) const{
            return this->h>cx.h;
        }
        bool operator()(const c &cx) const{
            return this->h>cx.h;
        }
    };
public:
    int trapRainWater(vector<vector<int>>& arr) {
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        if(!arr.size() || !arr[0].size()) return 0;
        int n=arr.size(),m=arr[0].size();
        int ans=0;
        priority_queue<c> pq;
        vector<vector<bool>> vis(n,vector<bool>(m,0));
        for(int i=0;i<n;i+=1){
            pq.push(c(arr[i][0],i,0));
            pq.push(c(arr[i][m-1],i,m-1));
            vis[i][0]=vis[i][m-1]=1;
        }
        for(int i=0;i<m;i+=1){
            pq.push(c(arr[0][i],0,i));
            pq.push(c(arr[n-1][i],n-1,i));
            vis[0][i]=vis[n-1][i]=1;
        }
        c cx(0,0,0);
        int d[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
        int i,j;
        while(!pq.empty()){
            cx=pq.top();
            pq.pop();
            for(auto v:d){
                i=cx.i+v[0],j=cx.j+v[1];
                if(i<0 || i>=n || j<0 || j>=m || vis[i][j]) continue;
                ans+=max(cx.h-arr[i][j],0);
                pq.push(c(max(arr[i][j],cx.h),i,j));
                vis[i][j]=1;
            }
        }
        return ans;
    }
};