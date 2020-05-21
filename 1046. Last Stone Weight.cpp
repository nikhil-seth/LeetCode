// 1046. Last Stone Weight

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        priority_queue<int> pq(stones.begin(),stones.end());
        int x,y;
        while(pq.size()>=2){
            x=pq.top();
            pq.pop();
            y=pq.top();
            pq.pop();
            if(x==y)
                continue;
            else
                pq.push(x-y);
        }
        if(pq.empty())
            return 0;
        return pq.top();
    }
};