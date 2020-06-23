// 40. Combination Sum II

class Solution {
public:
    vector<vector<int>> ans;
    void bt(vector<int> &v,int i,int val,vector<int> &cand){
        if(val<0) return;
        else if(val==0) ans.push_back(v);
        else if(i==cand.size()) return;
        else{
            for(int j=i;j<cand.size();j+=1){
                if(j>i && cand[j]==cand[j-1]) continue;
                v.push_back(cand[j]);
                bt(v,j+1,val-cand[j],cand);
                v.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target){
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        vector<int> v;
        sort(candidates.begin(),candidates.end());
        bt(v,0,target,candidates);
        
        return ans;
    }
};
