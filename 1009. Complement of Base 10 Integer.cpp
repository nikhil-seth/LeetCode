// 1009. Complement of Base 10 Integer

class Solution {
public:
    int bitwiseComplement(int num) {
        if(num==0)
            return 1;
        long x,i;
        x=0,i=1;
        while(num>=i){
            if((num&i)==0)
                x+=i;
            i=i<<1;
        }
        return x;
    }
};
        