// 973. K Closest Points to Origin
class Solution {
    struct cmp{
        bool operator()(const vector<int> &a,const vector<int> &b){
            long x,y;
            x=(long)(a[0]*a[0])+(long)(a[1]*a[1]);
            y=(long)(b[0]*b[0])+(long)(b[1]*b[1]);
            return x<y;
        }
    };
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K){
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        vector<long> v;
        priority_queue<vector<int>,vector<vector<int>>,cmp> pq;
        for(int i=0;i<points.size();i+=1){
            pq.push(points[i]);
            if(pq.size()>K)
                pq.pop();
        }
        vector<vector<int>> ans;
        while(!pq.empty()){
            ans.push_back(pq.top());
            pq.pop();
        }
        return ans;
    }
};
