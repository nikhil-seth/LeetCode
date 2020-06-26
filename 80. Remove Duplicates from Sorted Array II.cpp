// 80. Remove Duplicates from Sorted Array II

class Solution {
public:
    int removeDuplicates(vector<int>& nums){
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        if(!nums.size()) return 0;
        int i=0,j=1;
        bool f=0;
        while(j<nums.size()){
            cout<<i<<' '<<j<<endl;
            if(nums[i]==nums[j]){
                if(!f)
                    f=1,nums[++i]=nums[j++];
                else
                    j+=1;
            }
            else{
                nums[++i]=nums[j++];
                f=0;
            }
        }
        return i+1;
    }
};

        