// 41. First Missing Positive

class Solution {
public:
    int firstMissingPositive(vector<int>& nums){
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        int n=nums.size();
        for(int i=0,j,tmp;i<n;i+=1){
            j=nums[i];
            while(j>0 && j<=n && nums[j-1]!=j){
                tmp=nums[j-1];
                nums[j-1]=j;
                j=tmp;
            }
        }
        int ctr=1;
        for(int i=0;i<nums.size();i+=1){
            if(ctr==nums[i])
                ctr+=1;
        }
        return ctr;
    }
};
