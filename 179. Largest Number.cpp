// 179. Largest Number

class Solution {
public:
    static bool cmp(const string &s1,const string &s2){
        return s1+s2>s2+s1;
    }
    string largestNumber(vector<int>& nums){
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        if(nums.size()==0) return "0";
        if(nums.size()==1)
            return to_string(nums[0]);
        vector<string> arr;
        for(auto &x:nums)
            arr.push_back(to_string(x));
        sort(arr.begin(),arr.end(),cmp);
        string ans;
        for(auto &x:arr)
            ans.append(x);
        if(ans[0]=='0')
            return "0";
        return ans;
    }
};

        