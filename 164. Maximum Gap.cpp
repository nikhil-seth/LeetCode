// 164. Maximum Gap
    class Solution {
        struct B{
            bool used =false;
            int minval=INT_MAX,maxval=INT_MIN;
            void set(int &val){
                used=1;
                minval=min(minval,val);
                maxval=max(maxval,val);
            }
        };
    public:
        int maximumGap(vector<int>& nums){
            ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
            int n=nums.size();
            if(n<2) return 0;
            int ma=nums[0],mi=nums[0];

            for(int i=1;i<n;i+=1)
                ma=max(ma,nums[i]),mi=min(mi,nums[i]);
            int bs=max(1,(ma-mi)/(n-1));
            int bc=(ma-mi)/bs+1;
            vector<B> v(bc);
            for(int i=0;i<n;i+=1){
                int bi=(nums[i]-mi)/bs;
                v[bi].set(nums[i]);
            }
            int prevMax=mi;
            bs=(ma-mi)/(n-1);
            for(int i=0;i<bc;i+=1){
                if(v[i].used==false) continue;
                bs=max(bs,v[i].minval-prevMax);
                prevMax=v[i].maxval;
            }
            return bs;
        }
    };
