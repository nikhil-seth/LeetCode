// 1218. Longest Arithmetic Subsequence of Given Difference
class Solution {
public:
    int longestSubsequence(vector<int>& arr, int diff){
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        int n=arr.size();
        if(!n) return 0;
        unordered_map<int,int> m;
        int ans=1;
        for(int i=0;i<n;i+=1){
            m[arr[i]]=max(m[arr[i]],m[arr[i]-diff]+1);
            ans=max(ans,m[arr[i]]);
        }
        return ans;
    }
};

            