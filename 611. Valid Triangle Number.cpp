// 611. Valid Triangle Number

class Solution {
public:
    int triangleNumber(vector<int>& nums){
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        sort(nums.begin(),nums.end());
        int i,j,k,n=nums.size();
        int ctr=0;
        for(i=0;i<n-2;i+=1){
            k=i+2;
            for(int j=i+1;j<n-1 && nums[i]>0;j+=1){
                while(k<n && nums[i]+nums[j]>nums[k]){
                    k+=1;
                }
                ctr+=(k-j-1);
            }
        }
        return ctr;
    }
};