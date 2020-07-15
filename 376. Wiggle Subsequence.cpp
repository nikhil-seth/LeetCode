// 376. Wiggle Subsequence
class Solution {
public:
    int sg(int &a,int &b){
        if(a<b) return 1;
        else if(a>b) return -1;
        return 0;
    }
    int wiggleMaxLength(vector<int>& nums){
        if(!nums.size()) return 0;
        int lastSign=0,currentSign;
        int cl=1;
        for(int i=1;i<nums.size();i+=1){
            currentSign=sg(nums[i-1],nums[i]);
            if(currentSign!=lastSign && currentSign!=0)
                cl+=1,lastSign=currentSign;
        }
        return cl;
    }
};
