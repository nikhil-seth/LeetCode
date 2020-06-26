// 448. Find All Numbers Disappeared in an Array

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums){
        
        int n=nums.size();
        for(int i=0,tmp;i<n;i+=1){
            int j=nums[i];
            while(nums[j-1]!=j){
                tmp=nums[j-1];
                nums[j-1]=j;
                j=tmp;
            }
        }
        vector<int> ans;
        for(int i=1;i<=n;i+=1){
            if(nums[i-1]!=i)
                ans.push_back(i);
        }
        return ans;
    }
};
