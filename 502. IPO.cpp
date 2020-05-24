// 502. IPO

class Solution {
public:
    int findMaximizedCapital(int k, int W, vector<int>& Profits, vector<int>& Capital){
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        int n=Capital.size();
        vector<int> id(n);
        for(int i=0;i<n;i+=1)
            id[i]=i;
        sort(id.begin(),id.end(),[&Capital](const int &a,const int &b){
            return Capital[a]<Capital[b];
        });
        priority_queue<int> pq;
        int i=0;
        while(k){
            while(i<n && Capital[id[i]]<=W)
                pq.push(Profits[id[i++]]);
            if(pq.empty())
                break;
            k-=1;
            W+=pq.top(),pq.pop();
        }
        return W;
    }
};
