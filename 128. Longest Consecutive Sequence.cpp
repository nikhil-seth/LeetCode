// 128. Longest Consecutive Sequence

class Solution {
public:
    int longestConsecutive(vector<int>& nums){
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        unordered_set<int> s;
        int x,l,ml=0;
        for(int i=0;i<nums.size();i+=1)
            s.insert(nums[i]);
        for(int i=0;i<nums.size();i+=1){
            if(s.find(nums[i]-1)!=s.end())
                continue;
            l=1,x=nums[i]+1;
            while(s.find(x)!=s.end())
                l+=1,x+=1;
            ml=max(ml,l);
        }
        return ml;
    }
};
