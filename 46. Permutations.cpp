// 46. Permutations
class Solution {
public:
    vector<vector<int>> ans;
    void bt(vector<int> &nums,vector<bool> &vis,vector<int> &v,int i){
        
        if(i==nums.size()) ans.push_back(v);
        else{
            for(int j=0;j<nums.size();j+=1){
                if(!vis[j]){
                    vis[j]=1;
                    v[i]=nums[j];
                    bt(nums,vis,v,i+1);
                    vis[j]=0;
                }
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        vector<int> v(nums.size());
        vector<bool> vis(nums.size());
        bt(nums,vis,v,0);
        return ans;
    }
};
