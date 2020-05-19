// 239. Sliding Window Maximum

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k){
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        vector<int> v;
        deque<int> q;
        int i=0,j=0;
        for(i=0;i<k-1;i+=1){
            while(q.size()>0 && nums[q.back()]<=nums[i])
                q.pop_back();
            q.push_back(i);
        }
        while(i<nums.size()){
            while(q.size()>0 && q.front()<j)
                q.pop_front();
            while(q.size()>0 && nums[q.back()]<=nums[i])
                q.pop_back();
            q.push_back(i);
            v.push_back(nums[q.front()]);
            i+=1;
            j+=1;
        }
        return v;
    }
};

            
        