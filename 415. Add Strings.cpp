// 415. Add Strings

class Solution {
public:
    string addStrings(string num1, string num2){
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        string ans;
        int n=num1.length()-1,m=num2.length()-1;
        int c=0;
        while(n>=0 && m>=0){
            c=num1[n]-48+num2[m]-48+c;
            ans.push_back(c%10+48);
            c/=10;
            n-=1,m-=1;
        }
        while(n>=0){
            c=num1[n--]-48+c;
            ans.push_back(c%10+48);
            c/=10;
        }
        while(m>=0){
            c=num2[m--]-48+c;
            ans.push_back(c%10+48);
            c/=10;
        }
        if(c)
            ans.push_back(c+48);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
