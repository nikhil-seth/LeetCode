// 189. Rotate Array

class Solution {
public:
    void rotate(vector<int>& nums, int k){
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        int n=nums.size();
        k%=n;
        reverse(nums.begin(),nums.end());
        reverse(nums.begin(),nums.begin()+k);
        reverse(nums.begin()+k,nums.end());
    }
    
};
