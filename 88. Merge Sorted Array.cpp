// 88. Merge Sorted Array

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n){
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        int i=n+m-1;
        n-=1,m-=1;
        while(n>=0 && m>=0){
            if(nums1[m]>nums2[n])
                nums1[i--]=nums1[m--];
            else
                nums1[i--]=nums2[n--];
        }
        while(n>=0)
            nums1[i--]=nums2[n--];
    }
};
        