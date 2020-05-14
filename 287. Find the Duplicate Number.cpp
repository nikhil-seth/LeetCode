// 287. Find the Duplicate Number
class Solution {
public:
    int findDuplicate(vector<int>& nums){
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        int h,t;
        h=t=nums[0];
        do{
            h=nums[nums[h]];
            t=nums[t];
        }while(h!=t);
        h=nums[0];
        while(h!=t){
            h=nums[h];
            t=nums[t];
        }
        return h;
    }
};