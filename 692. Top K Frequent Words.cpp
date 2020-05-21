// 692. Top K Frequent Words

class Solution {
    struct cmp{
        bool operator()(const pair<int,string> &p1,const pair<int,string> &p2){
            if(p1.first==p2.first)
                return p1.second>p2.second;
            return p1.first<p2.first;
        }
    };
public:
    vector<string> topKFrequent(vector<string>& words, int k){
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        map<string,int> m;
        for(auto s:words)
            m[s]+=1;
        priority_queue<pair<int,string>,vector<pair<int,string>>,cmp> pq;
        for(auto c:m)
            pq.push({c.second,c.first});
        vector<string> ans;
        while(k--){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};
