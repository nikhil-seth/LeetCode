// 125. Valid Palindrome
class Solution {
public:
    bool isPalindrome(string s){
        // Consider Only Alphanumeric Characters.
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        int i=0,j=s.length()-1;
        while(i<j){
            if(!isalnum(s[i])) i+=1;
            else if(!isalnum(s[j])) j-=1;
            else{
                if(tolower(s[i])!=tolower(s[j])) return 0;
                i+=1,j-=1;
            }
        }
        return 1;
    }
};
