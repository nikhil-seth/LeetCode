// 347. Top K Frequent Elements
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k){
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        unordered_map<int,int> m;
        vector<int> ans;
        vector<vector<int>> bucket(nums.size()+1);
        for(auto c:nums)
            m[c]+=1;
        for(auto c:m)
            bucket[c.second].push_back(c.first);
        for(int i=nums.size();i>=0 && k>0;i-=1){
            for(auto c:bucket[i]){
                if(!k) break;
                ans.push_back(c),k-=1;
            }
            if(!k) break;
        }
        return ans;
    }
};
