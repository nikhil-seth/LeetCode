// 78. Subsets

class Solution {
public:
    vector<vector<int>> ans;
    void bt(vector<int> &nums,vector<int> &v,int i){
        if(i==nums.size())
            ans.push_back(v);
        else{
            bt(nums,v,i+1);
            v.push_back(nums[i]);
            bt(nums,v,i+1);
            v.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums){
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        vector<int> v;
        bt(nums,v,0);
        return ans;
    }
};

        