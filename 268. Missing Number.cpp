// 268. Missing Number

class Solution {
public:
    int missingNumber(vector<int>& nums){
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        int n=nums.size();
        for(int i=0,tmp;i<n;i+=1){
            int j=nums[i];
            while(j<n && nums[j]!=j){
                tmp=nums[j];
                nums[j]=j;
                j=tmp;
            }
        }
        for(int i=0;i<n;i+=1){
            if(nums[i]!=i) return i;
        }
        return n;
    }
};
