// 852. Peak Index in a Mountain Array

static auto io=[](){ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);return 0;}();
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A){
        int l=0,r=A.size()-1,mid;
        while(l<r){
            mid=l+(r-l)/2;
            if(A[mid]<A[mid+1])
                l=mid+1;
            else
                r=mid;
        }
        return l;
    }
};

