// 880. Decoded String at Index

class Solution {
public:
    string decodeAtIndex(string S, int K) {
        long len=0,i;
        for(i=0;len<K;i++){
            if(isdigit(S[i]))
                len*=(S[i]-'0');
            else
                len+=1;
        }
        do{
            i--;
            if(isdigit(S[i])){
                len/=(S[i]-'0');
                K%=len;
            }
            else{
                if(K%len==0)
                    return string(1,S[i]);
                len--;
            }
        }while(i);
        return string(1,S[0]);
    }
};
