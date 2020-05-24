// 313. Super Ugly Number

#define pii pair<int,int>
class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes){
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        if(n==1)
            return 1;
        vector<int> id(primes.size(),0);
        priority_queue<pii,vector<pii>,greater<pii>> pq;
        int qt=primes.size(),x;
        vector<int> v;
        v.push_back(1);
        for(int i=0;i<qt;i+=1)
            pq.push({primes[i],i});
        pii p;
        n-=2;
        while(n--){
            p=pq.top();
            v.push_back(p.first);
            while(!pq.empty() && p.first==pq.top().first){
                x=pq.top().second;
                pq.pop();
                pq.push({v[++id[x]]*primes[x],x});
            }
        }
        return pq.top().first;
    }
};
