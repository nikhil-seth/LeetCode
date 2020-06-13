// 26. Remove Duplicates from Sorted Array

class Solution {
public:
    int removeDuplicates(vector<int>& nums){
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        if(nums.size()==0) return 0;
        int i=1,j=0;
        while(i<nums.size()){
            while(i<nums.size() && nums[i]==nums[j])
                i+=1;
            if(i==nums.size()) break;
            swap(nums[i],nums[++j]);
            i+=1;
        }
        return j+1;
    }
};