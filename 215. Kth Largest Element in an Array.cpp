// 215. Kth Largest Element in an Array

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k){
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        int lo=0,hi=nums.size()-1;
        swap(nums[0],nums[nums.size()-1]);
        int piv,i,j;
        k=nums.size()-k;
        while(lo<=hi){
            piv=hi,i=lo,j=lo;
            while(i<hi){
                if(nums[i]<nums[piv]){
                    swap(nums[i],nums[j]);
                    j+=1;
                }
                i+=1;
            }
            swap(nums[j],nums[piv]);
            if(j==k)
                return nums[j];
            else if(j>k)
                hi=j-1;
            else
                lo=j+1;
        }
        return nums[lo];
    }
};

        