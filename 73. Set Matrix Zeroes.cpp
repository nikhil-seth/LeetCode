// 73. Set Matrix Zeroes

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix){
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        if(matrix.size()==0 || matrix[0].size()==0) return;
        bool rm=0,cm=0;
        for(int i=0;i<matrix.size()&& !rm;i+=1){
            if(matrix[i][0]==0) rm=1;
        }
        for(int i=0;i<matrix[0].size()&& !cm;i+=1){
            if(matrix[0][i]==0) cm=1;
        }
        for(int i=1;i<matrix.size();i+=1){
            for(int j=1;j<matrix[0].size();j+=1){
                if(matrix[i][j]==0)
                    matrix[i][0]=matrix[0][j]=0;
            }
        }
        for(int i=1;i<matrix.size();i+=1){
            if(matrix[i][0]==0){
                for(int j=1;j<matrix[0].size();j+=1)
                    matrix[i][j]=0;
            }
        }
        for(int i=1;i<matrix[0].size();i+=1){
            if(matrix[0][i]==0){
                for(int j=1;j<matrix.size();j+=1)
                    matrix[j][i]=0;
            }
        }
        if(rm){
            for(int i=0;i<matrix.size();i+=1)
                matrix[i][0]=0;
        }
        if(cm){
            for(int i=0;i<matrix[0].size();i+=1)
                matrix[0][i]=0;
        }
    }
};
