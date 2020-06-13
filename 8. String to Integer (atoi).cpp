// 8. String to Integer (atoi)

class Solution {
public:
    int myAtoi(string s){
        long integer=0,sign=1;
        for(int i=0;i<s.length();i+=1){
            if(s[i]==' ')
                continue;
            else if(s[i]=='-' || s[i]=='+' || isdigit(s[i])){
                if(s[i]=='-'){
                    if(i==s.length()-1 || !isdigit(s[i+1]))
                        return 0;
                    sign=-1;
                    i+=1;
                }
                else if(s[i]=='+')
                    i+=1;
                while(i<s.length() && isdigit(s[i]) && integer<INT_MAX && integer>INT_MIN)
                    integer=integer*10+(s[i++]-48);
                break;
            }
            else
                break;
        }
        integer*=sign;
        if(integer<INT_MIN) return INT_MIN;
        if(integer>INT_MAX) return INT_MAX;
        return integer;
    }
};
