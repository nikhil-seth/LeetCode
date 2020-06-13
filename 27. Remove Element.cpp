// 27. Remove Element
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        if(!nums.size()) return 0;
        int i=0,j=nums.size()-1;
        while(i<=j){
            if(nums[i]==val)
                swap(nums[i],nums[j--]);
            else
                i+=1;
        }
        return i;
    }
};
