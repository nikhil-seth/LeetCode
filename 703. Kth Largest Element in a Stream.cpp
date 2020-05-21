// 703. Kth Largest Element in a Stream

class KthLargest {
    priority_queue<int,vector<int>,greater<int>> pq;
    int k;
public:
    KthLargest(int k2, vector<int>& nums){
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        k=k2;
        for(int i=0;i<nums.size() && i<k;i+=1)
            pq.push(nums[i]);
        for(int i=k;i<nums.size();i+=1)
            pq.push(nums[i]),pq.pop();
    }
    int add(int val){
        pq.push(val);
        if(pq.size()>k)
            pq.pop();
        return pq.top();
    }
};
/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */