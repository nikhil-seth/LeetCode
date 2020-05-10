// 1337. The K Weakest Rows in a Matrix

static auto io=[](){ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);return 0;}();
class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k){
        priority_queue<pair<int,int>> pq;
        int lo,hi,mid,x;
        for(int i=0;i<mat.size();i+=1){
            lo=0; hi=mat[0].size()-1;
            x=hi+1;
            while(lo<=hi){
                mid=(lo+hi)/2;
                if(mat[i][mid]==1)
                    lo=mid+1;
                else{
                    hi=mid-1;
                    x=mid;
                }
            }
            pq.push(make_pair(x,i));
            if(pq.size()>k)
                pq.pop();
        }
        vector<int> v;
        while(!pq.empty()){
            v.push_back(pq.top().second);
            pq.pop();
        }
        reverse(v.begin(),v.end());
        return v;
    }
};