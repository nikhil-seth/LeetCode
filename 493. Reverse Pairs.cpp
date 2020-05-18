// 493. Reverse Pairs

class Solution {
public:
    int ans=0;
    vector<int> vec,arr;
    void merge(vector<int> &nums,int lo,int hi){
        int mid=lo+(hi-lo)/2;
        int i=lo,j=mid+1,k=lo;
        while(i<=mid && j<=hi){
            if(nums[arr[i]]>long(2)*nums[arr[j]]){
                ans+=(mid-i+1);
                j+=1;
            }
            else
                i+=1;
        }
        i=lo,j=mid+1;
        while(i<=mid && j<=hi){
            if(nums[arr[i]]<nums[arr[j]])
                vec[k++]=arr[i++];
            else
                vec[k++]=arr[j++];
        }
        while(i<=mid)
            vec[k++]=arr[i++];
        while(j<=hi)
            vec[k++]=arr[j++];
        for(i=lo;i<=hi;i+=1)
            arr[i]=vec[i];
    }
    void msort(vector<int>&nums,int lo,int hi){
        if(lo>=hi) return;
        int mid=lo+(hi-lo)/2;
        msort(nums,lo,mid);
        msort(nums,mid+1,hi);
        merge(nums,lo,hi);
    }
    int reversePairs(vector<int>& nums){
        vec=vector<int>(nums.size());
        for(int i=0;i<nums.size();i+=1)
            arr.push_back(i);
        msort(nums,0,nums.size()-1);
        return ans;
    }
};
