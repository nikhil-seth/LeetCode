// 9. Palindrome Number
class Solution {
public:
    bool isPalindrome(int x){
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        if(x<0) return 0;
        long y,z;
        y=0,z=x;
        while(x){
            y=y*10+x%10;
            x/=10;
        }
        if(y==z) return 1;
        return 0;
    }
};
