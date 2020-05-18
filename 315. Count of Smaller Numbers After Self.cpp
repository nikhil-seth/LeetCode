// 315. Count of Smaller Numbers After Self
static auto io=[](){ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);return 0;}();
class Solution {
    vector<int> cnt,arr,vec;
public:
    void merge(vector<int> &nums,int lo,int hi){
        int mid=lo+(hi-lo)/2;
        int i=lo,j=mid+1,k=lo;
        while(i<=mid && j<=hi){
            if(nums[arr[i]]<=nums[arr[j]]){
                vec[k++]=arr[i];
                cnt[arr[i++]]+=(j-mid-1);
            }
            else
                vec[k++]=arr[j++];
        }
        while(i<=mid){
            vec[k++]=arr[i];
            cnt[arr[i++]]+=(j-mid-1);
        }
        while(j<=hi)
            vec[k++]=arr[j++];
        for(int idx=lo;idx<=hi;idx+=1){
            arr[idx]=vec[idx];
           // cout<<nums[arr[idx]]<<' '<<cnt[arr[idx]]<<endl;
        }
    }
    void mergesort(vector<int> &nums,int lo,int hi){
        if(lo>=hi)
            return;
        int mid=lo+(hi-lo)/2;
        mergesort(nums,lo,mid);
        mergesort(nums,mid+1,hi);
        merge(nums,lo,hi);
    }
    vector<int> countSmaller(vector<int>& nums){
        int n=nums.size();
        arr=vector<int>(n);
        cnt=vector<int>(n);
        vec=vector<int>(n);
        for(int i=0;i<n;i+=1)
            arr[i]=i,cnt[i]=0;
        mergesort(nums,0,n-1);
        return cnt;
    }
};

        
