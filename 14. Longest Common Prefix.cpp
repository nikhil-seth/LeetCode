// 14. Longest Common Prefix
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs){
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        int i=0;
        string x;
        if(strs.size()==0) return x;
        for(i=0;i<strs[0].length();i+=1){
            for(int j=1;j<strs.size();j+=1){
                if(i>=strs[j].length() || strs[j][i]!=strs[0][i]) return x;
            }
            x.push_back(strs[0][i]);
        }
        return x;
    }
};
