// 229. Majority Element II
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums){
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        int n=nums.size();
        int ctr1,ctr2,c1,c2;
        ctr1=ctr2=0,c1=0,c2=1;
        for(int i=0;i<n;i+=1){
            if(nums[i]==c1)
                ctr1+=1;
            else if(nums[i]==c2)
                ctr2+=1;
            else if(ctr1==0)
                c1=nums[i],ctr1=1;
            else if(ctr2==0)
                c2=nums[i],ctr2=1;
            else
                ctr1-=1,ctr2-=1;
        }
        ctr1=ctr2=0;
        for(int i=0;i<n;i+=1){
            if(nums[i]==c1)
                ctr1+=1;
            else if(nums[i]==c2)
                ctr2+=1;
        }
        vector<int> ans;
        if(ctr1>(n/3))
            ans.push_back(c1);
        if(ctr2>(n/3))
            ans.push_back(c2);
        return ans;
    }
};