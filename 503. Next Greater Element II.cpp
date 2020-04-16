// 503. Next Greater Element II
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        if(nums.size()<=0){
            vector<int> v;
            return v;
        }
        int max_idx=0;
        for(int i=1;i<nums.size();i++){
            if(nums[max_idx]<nums[i])
                max_idx=i;
        }
        vector<int> v(nums.size());
        stack<int> s;
        int i=max_idx;
        do{
            while(!s.empty() && s.top()<=nums[i])
                s.pop();
            if(s.empty())
                v[i]=-1;
            else
                v[i]=s.top();
            s.push(nums[i]);
            i=(i-1+nums.size())%nums.size();
        }while(i!=max_idx);
        return v;
    }
};
