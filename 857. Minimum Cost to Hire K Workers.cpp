// 857. Minimum Cost to Hire K Workers

class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int K){
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        int n=quality.size();
        int rat[n];
        for(int i=0;i<n;i+=1)
            rat[i]=i;
        sort(rat,rat+n,[&quality,&wage](const int &a,const int &b){
            return (double(wage[a])/quality[a])<(double(wage[b])/quality[b]);
        });
        priority_queue<int> pq;
        double ans=1e9;
        double tv=0;
        for(int i=0;i<n;i+=1){
            pq.push(quality[rat[i]]);
            tv+=quality[rat[i]];
            if(pq.size()>K)
                tv-=pq.top(),pq.pop();
            if(pq.size()==K)
                ans=min(ans,tv*double(wage[rat[i]])/quality[rat[i]]);
        }
        return ans;
    }
};
