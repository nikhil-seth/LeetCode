// 22. Generate Parentheses

class Solution {
public:
    vector<string> ans;
    string x;
    void bt(int i,int j,int idx){
        if(i==0 && j==0){
            ans.push_back(x);
            return;
        }
        if(i<j){
            x[idx]=')';
            bt(i,j-1,idx+1);
        }
        if(i!=0){
            x[idx]='(';
            bt(i-1,j,idx+1);
        }
    }
    vector<string> generateParenthesis(int n) {
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        x.resize(2*n);
        bt(n,n,0);
        return ans;
    }
};