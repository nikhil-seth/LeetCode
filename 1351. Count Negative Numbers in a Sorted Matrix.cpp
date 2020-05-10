// 1351. Count Negative Numbers in a Sorted Matrix
static auto io=[](){ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);return 0;}();
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int n=grid.size();
        if(!n) return 0;
        int m=grid[0].size();
        int lo=0,hi=m-1,mid,ans=0,x=m-1;
        for(int i=0;i<n;i++){
            lo=0;
            hi=x;
            while(lo<=hi){
                mid=lo+(hi-lo)/2;
                if(grid[i][mid]>=0)
                    lo=mid+1;
                else{
                    x=mid;
                    hi=mid-1;
                }
            }
            if(grid[i][x]<0)
                ans+=(m-x);
        }
        return ans;
    }
};