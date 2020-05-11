// 74. Search a 2D Matrix

static auto io=[](){ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);return 0;}();
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target){
        if(!matrix.size() || !matrix[0].size())
            return 0;
        int n=matrix.size(),m=matrix[0].size();
        int lo=0,hi=m*n-1,mid;
        while(lo<=hi){
            mid=lo+(hi-lo)/2;
            if(matrix[mid/m][mid%m]==target)
                return 1;
            else if(matrix[mid/m][mid%m]>target)
                hi=mid-1;
            else
                lo=mid+1;
        }
        return 0;
    }
};
