// 151. Reverse Words in a String

class Solution {
public:
    string reverseWords(string s) {
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        stringstream o(s);
        string ans;
        while(o>>s){
            reverse(s.begin(),s.end());
            ans.append(s);
            ans.push_back(' ');
        }
        if(ans.length()>0)
            ans.pop_back();
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
