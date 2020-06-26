// 118. Pascal's Triangle

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        vector<vector<int>> ans(numRows);
        if(numRows==0) return ans;
        ans[0].push_back(1);
        for(int i=1;i<numRows;i+=1){
            ans[i].push_back(1);
            for(int j=1;j<i;j+=1)
                ans[i].push_back(ans[i-1][j]+ans[i-1][j-1]);
            ans[i].push_back(1);
        }
        return ans;
    }
};
