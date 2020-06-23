// 31. Next Permutation

class Solution {
public:
    void nextPermutation(vector<int>& nums){
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        // Array No 6 in Notes.
        if(nums.size()==0) return;
        int i=nums.size()-1;
        while(i>0 && nums[i-1]>=nums[i])
            i-=1;
        if(i==0){
            reverse(nums.begin(),nums.end());
        }
        else{
            int j=i;
            while(j<nums.size() && nums[j]>nums[i-1])
                j++;
            j-=1;
            swap(nums[i-1],nums[j]);
            reverse(nums.begin()+i,nums.end());
        }
    }
};
        
        