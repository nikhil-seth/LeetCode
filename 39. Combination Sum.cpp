// 39. Combination Sum

class Solution {
public:
    vector<vector<int>> ans;
    void bt(vector<int> &v,int i,int val,vector<int> &c){
        if(val<0) return;
        if(c.size()==i){
            if(val==0)
                ans.push_back(v);
            return;
        }
        bt(v,i+1,val,c);
        v.push_back(c[i]);
        bt(v,i,val-c[i],c);
        v.pop_back();
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target){
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        vector<int> v;
        bt(v,0,target,candidates);
        return ans;
    }
};