// 45. Jump Game II

class Solution {
public:
    int jump(vector<int>& nums){
        // reachable -> will be integer denoting till where we can go.
        // jump->will count total jumps.
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        if(nums.size()<=1) return 0;
        int jump=0,step=1,reachable=0;
        for(int i=0;i<nums.size();i+=1){
            if(step--)
                reachable=max(reachable,i+nums[i]);
            if(step==0){
                jump+=1;
                step=reachable-i;
                if(i+step>=nums.size()-1)
                    break;
            }
        }
        return jump;
    }
};