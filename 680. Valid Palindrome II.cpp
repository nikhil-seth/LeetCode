// 680. Valid Palindrome II
class Solution {
public:
    bool chk(string &s,int i,int j){
        while(i<j){
            if(s[i]!=s[j]) return 0;
            i+=1,j-=1;
        }
        return 1;
    }
    bool validPalindrome(string s){
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        int i=0,j=s.length()-1;
        while(i<j){
            if(s[i]!=s[j]){
                return chk(s,i+1,j) || chk(s,i,j-1);
            }
            i+=1,j-=1;
        }
        return 1;
    }
};
