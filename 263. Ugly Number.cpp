// 263. Ugly Number

class Solution {
public:
    bool isUgly(int num){
        //ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        while(num>1 && num%2==0)
            num/=2;
        while(num>1 && num%3==0)
            num/=3;
        while(num>1 && num%5==0)
            num/=5;
        return num==1;
    }
};

        