// 4. Median of Two Sorted Arrays
// TC= O(log(min(n,m)))
static auto io=[](){ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);return 0;}();
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2){
        if(nums1.size()>nums2.size())
            swap(nums1,nums2);
        int m=nums1.size(),n=nums2.size(),lo=0,hi=m,i,j,hv=(n+m+1)/2;
        while(lo<=hi){
            i=lo+(hi-lo)/2,j=hv-i;
            if(i<m && nums2[j-1]>nums1[i]) // j>0, always in this case
                lo=i+1;
            else if(i>0 && nums1[i-1]>nums2[j])
                hi=i-1;
            else
                break;
        }
        //cout<<i<<' '<<j<<' '<<m<<' '<<n<<endl;
        int max_left,min_right;
        if(!i)
            max_left=nums2[j-1];
        else if(!j)
            max_left=nums1[i-1];
        else
            max_left=max(nums1[i-1],nums2[j-1]);
        if((n+m)%2!=0)
            return max_left;
        if(i==m)
            min_right=nums2[j];
        else if(j==n)
            min_right=nums1[i];
        else
            min_right=min(nums1[i],nums2[j]);
        return (max_left+min_right)/2.0;
    }
};