// 73. Set Matrix Zeroes

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix){
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        if(matrix.size()==0 || matrix[0].size()==0) return;
        int n=matrix.size(),m=matrix[0].size();
        bool rm=0,cm=0;
        for(int i=0;i<n && !rm;i+=1){
            if(matrix[i][0]==0) rm=1;
        }
        for(int i=0;i<m && !cm;i+=1){
            if(matrix[0][i]==0) cm=1;
        }
        
        
        for(int i=1;i<n;i+=1){
            for(int j=1;j<m;j+=1){
                if(matrix[i][j]==0)
                    matrix[i][0]=matrix[0][j]=0;
            }
        }
        for(int i=1;i<n;i+=1){
            if(matrix[i][0]==0){
                for(int j=1;j<m;j+=1)
                    matrix[i][j]=0;
            }
        }
        for(int i=1;i<m;i+=1){
            if(matrix[0][i]==0){
                for(int j=1;j<n;j+=1)
                    matrix[j][i]=0;
            }
        }
        if(rm){
            for(int i=0;i<n;i+=1)
                matrix[i][0]=0;
        }
        if(cm){
            for(int i=0;i<m;i+=1)
                matrix[0][i]=0;
        }
    }
};
