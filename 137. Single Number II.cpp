// 137. Single Number II

class Solution {
public:
    int singleNumber(vector<int>& nums){
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        int n=nums.size();
        int no=0;
        for(int i=0;i<32;i+=1){
            int ctr=0;
            for(int j=0;j<n;j+=1){
                if(nums[j]&1)
                    ctr+=1;
                nums[j]=nums[j]>>1;
            }
            if(ctr%3!=0)
                no|=(1<<i);
        }
        return no;
    }
};

            
            