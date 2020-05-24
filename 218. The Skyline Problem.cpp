// 218. The Skyline Problem
#define pii pair<int,int>
class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& arr){
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        sort(arr.begin(),arr.end(),[](const vector<int> &v1,const vector<int> &v2){
            if(v1[0]==v2[0])
                return v1[2]>v2[2];
            return v1[0]<v2[0];
        });
        priority_queue<pii> pq;
        int i=0;
        vector<vector<int>> ans;
        vector<int> v(2);
        int prev_max=0,prev_idx=0;
        while(i<arr.size()){
            while(!pq.empty() && arr[pq.top().second][1]<arr[i][0]){
                v[0]=arr[pq.top().second][1];
                pq.pop();
                if(prev_idx>=v[0])
                    continue;
                while(!pq.empty()){
                    if(arr[pq.top().second][1]>v[0]){
                        v[1]=pq.top().first,prev_max=pq.top().first;
                        break;
                    }
                    else
                        pq.pop();
                }
                if(pq.empty())
                    v[1]=0,prev_max=0;
                prev_idx=v[0];
                ans.push_back(v);
            }
            pq.push({arr[i][2],i});
            if(prev_max<pq.top().first){
                v[0]=arr[pq.top().second][0],v[1]=pq.top().first;
                ans.push_back(v);
                prev_max=pq.top().first;
                prev_idx=arr[i][0];
            }
            i+=1;
        }
        while(!pq.empty()){
            v[0]=arr[pq.top().second][1];
            pq.pop();
            if(prev_idx>=v[0])
                continue;
            while(!pq.empty()){
                    if(arr[pq.top().second][1]>v[0]){
                        v[1]=pq.top().first,prev_max=pq.top().first;
                        break;
                    }
                    else
                        pq.pop();
            }
            if(pq.empty())
                v[1]=0,prev_max=0;
                
            prev_idx=v[0];
            ans.push_back(v);
        }
        return ans;
    }
};
