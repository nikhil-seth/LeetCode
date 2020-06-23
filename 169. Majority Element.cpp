// 169. Majority Element

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        // Boyer Moore Voting Algo.
        int candidate=nums[0];
        int count=1;
        for(int i=1;i<nums.size();i+=1){
            if(count==0)
                candidate=nums[i];
            if(nums[i]==candidate)
                count+=1;
            else
                count-=1;
        }
        return candidate;
    }
};