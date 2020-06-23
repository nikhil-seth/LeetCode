// 216. Combination Sum III
class Solution {
public:
    vector<vector<int>> ans;
    void bt(vector<int> &v,int i,int k,int val){
        if(k==0){
            if(val==0)
                ans.push_back(v);
        }
        else if(i==10 || val<0){
            return;
        }
        else{
            bt(v,i+1,k,val);
            v.push_back(i);
            bt(v,i+1,k-1,val-i);
            v.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n){
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        vector<int> v;
        bt(v,1,k,n);
        return ans;
    }
};