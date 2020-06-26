// 48. Rotate Image

class Solution {
public:
    void rotate(vector<vector<int>>& matrix){
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        int n=matrix.size();
        for(int j=0;j<n;j+=1,n-=1){
            for(int i=0;i<n-1-j;i+=1){
                cout<<j<<' '<<i<<' '<<n-1<<endl;
                swap(matrix[j][i+j],matrix[i+j][n-1]);
                swap(matrix[j][i+j],matrix[n-1][n-i-1]);
                swap(matrix[j][i+j],matrix[n-1-i][j]);
            }
        }
    }
};
