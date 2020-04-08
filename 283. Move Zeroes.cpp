//283. Move Zeroes

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size();
        for(int x=0,i=0;i<n;i++){
            if(nums[i])
                swap(nums[x++],nums[i]);
        }
    }
};