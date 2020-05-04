// 476. Number Complement

class Solution {
public:
    int findComplement(int num) {
        long x,i;
        x=0,i=1;
        while(num>i){
            if((num&i)==0)
                x+=i;
            i=i<<1;
        }
        return x;
    }
};