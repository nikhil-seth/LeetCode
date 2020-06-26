// 90. Subsets II
class Solution {
public:
    vector<vector<int>> ans;
    void bt(vector<int> &nums,vector<int> &v,int i){
        //cout<<i<<endl;
        for(int j=i;j<nums.size();j+=1){
            if(j>i && nums[j]==nums[j-1]) continue;
            v.push_back(nums[j]);
            bt(nums,v,j+1);
            v.pop_back();
        }
        ans.push_back(v);

//        cout<<"Backtrack"<<i<<endl;
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums){
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        sort(nums.begin(),nums.end());
        vector<int> v;
        bt(nums,v,0);
        return ans;
    }
};

        