// 131. Palindrome Partitioning

class Solution {
public:
    bool checkPalindrome(string &s,int i,int j){
        while(i<j){
            if(s[i]!=s[j]) return 0;
            i+=1,j-=1;
        }
        return 1;
    }
    vector<vector<string>> ans;
    void bt(vector<string> &v,string &s,int i){
        if(i==s.length()){
            ans.push_back(v);
            return;
        }
        v.push_back("#");
        for(int j=i;j<s.length();j+=1){
            if(checkPalindrome(s,i,j)){
                v.back()=s.substr(i,j-i+1);
                bt(v,s,j+1);
            }
        }
        v.pop_back();
    }
    vector<vector<string>> partition(string s){
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        vector<string> v;
        bt(v,s,0);
        return ans;
    }
};
