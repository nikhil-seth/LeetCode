// 240. Search a 2D Matrix II

static auto io=[](){ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);return 0;}();
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target){
        if(!matrix.size() || !matrix[0].size()) return 0;
        int x=0,y=matrix[0].size()-1;
        while(x<matrix.size()){
            while(y>=0 && matrix[x][y]>target) y-=1;
            if(y>=0 && matrix[x][y]==target) return 1;
            x+=1;
        }
        return 0;
    }
};