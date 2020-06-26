// 77. Combinations

class Solution {
public:
    vector<vector<int>> ans;
    void bt(vector<int> &v,int j,const int &n,int k,int idx){
        if(k==0)
            ans.push_back(v);
        else{
            for(int i=j;i<=n;i+=1){
                v[idx]=i;
                bt(v,i+1,n,k-1,idx+1);
            }
        }
    }
    
    vector<vector<int>> combine(int n, int k){
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        vector<int> v(k);
        bt(v,1,n,k,0);
        return ans;
    }
};
