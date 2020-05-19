//  327. Count of Range Sum

class Solution {
    vector<long> prefix,temp;
    int ans;
public:
    void mergesort(int lo,int hi,const long &lower,const long &upper){
        if(lo>=hi)
            return;
        int mid=lo+(hi-lo)/2;
        mergesort(lo,mid,lower,upper);
        mergesort(mid+1,hi,lower,upper);
        int i=lo,j=mid+1,k=mid+1,p=lo,q=mid+1;
        while(i<=mid){
            while(j<=hi && prefix[j]-prefix[i]<lower) j+=1;
            while(k<=hi && prefix[k]-prefix[i]<=upper) k+=1;
            ans+=(k-j);
            while(q<=hi && prefix[i]>prefix[q])
                temp[p++]=prefix[q++];
            temp[p++]=prefix[i++];
        }
        while(q<=hi)
            temp[p++]=prefix[q++];
        for(i=lo;i<=hi;i+=1)
            prefix[i]=temp[i];
    }
    int countRangeSum(vector<int>& nums, int lower, int upper){
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        prefix=vector<long>(nums.size()+1);
        temp=vector<long>(nums.size()+1);
        ans=0;
        prefix[0]=0;
        for(int i=0;i<nums.size();i+=1)
            prefix[i+1]=nums[i]+prefix[i];
        mergesort(0,nums.size(),lower,upper);
        return ans;
    }
};
