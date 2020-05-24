// 986. Interval List Intersections
class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B){
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        vector<vector<int>> ans;
        vector<int> v(2);
        int i=0,j=0;
        while(i<A.size() && j<B.size()){
            if(A[i][1]<B[j][0])
                i+=1;
            else if(A[i][0]>B[j][1])
                j+=1;
            else{
                v[0]=max(A[i][0],B[j][0]);
                v[1]=min(A[i][1],B[j][1]);
                ans.push_back(v);
                if(A[i][1]<B[j][1])
                    i+=1;
                else
                    j+=1;
            }
        }
        return ans;
    }
};