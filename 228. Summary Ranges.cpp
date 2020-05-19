// 228. Summary Ranges

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums){
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        vector<string> v;
        if(!nums.size())
            return v;
        string s;
        int si=0,ei=0;
        for(int i=1;i<nums.size();i+=1){
            if(nums[ei]==nums[i]-1)
                ei+=1;
            else{
                s=to_string(nums[si])+((si==ei)?"":("->"+to_string(nums[ei])));
                v.push_back(s);
                si=ei=i;
            }
        }
        s=to_string(nums[si])+((si==ei)?"":("->"+to_string(nums[ei])));
        v.push_back(s);
        return v;
    }
};