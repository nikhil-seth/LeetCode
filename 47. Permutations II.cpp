// 47. Permutations II

class Solution {
public:
    int n;
    vector<vector<int>> ans;
    void bt(vector<int> &v,int i,vector<int> &nums,vector<bool> &vis){
        if(i==n) ans.push_back(v);
        else{
            v.push_back(0);
            for(int j=0;j<n;j+=1){
                if(vis[j]) continue;
                if(j>0 && nums[j]==nums[j-1] && !vis[j-1]) continue;
                v[i]=nums[j];
                vis[j]=1;
                bt(v,i+1,nums,vis);
                vis[j]=0;
            }
            v.pop_back();
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        n=nums.size();
        vector<int> v;
        vector<bool> vis(n,0);
        sort(nums.begin(),nums.end());
        bt(v,0,nums,vis);
        return ans;
    }
};