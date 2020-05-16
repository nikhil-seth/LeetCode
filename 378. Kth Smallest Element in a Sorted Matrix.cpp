// 378. Kth Smallest Element in a Sorted Matrix
// Binary Search Method
class Solution {
public:
    int fn(vector<vector<int>>& matrix,int mid,vector<int> &v){
        int n=matrix.size(),r=0,c=n-1,ctr=0;
        while(r<n){
            while(c>=0 && matrix[r][c]>mid){
                v[1]=min(v[1],matrix[r][c]);
                c-=1;
            }
            if(c>=0)
                v[0]=max(v[0],matrix[r][c]);
            ctr+=c+1,r+=1;
        }
        return ctr;
    }
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        int n=matrix.size();
        if(!n) return 0;
        int lo=matrix[0][0],hi=matrix[n-1][n-1],mid,ctr;
        vector<int> v(2);
        while(lo<hi){
            mid=lo+(hi-lo)/2;
            v[0]=lo; v[1]=hi;
            ctr=fn(matrix,mid,v);
            if(ctr==k)
                return v[0];
            else if(ctr>k)
                hi=v[0];
            else
                lo=v[1];
        }
        return lo;
    }
};
