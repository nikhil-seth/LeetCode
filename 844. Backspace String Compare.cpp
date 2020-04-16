// 844. Backspace String Compare

class Solution {
public:
    bool backspaceCompare(string S, string T) {
        int i,i1,i2;
        for(i=0,i1=0;i<S.length();i++){
            if(S[i]!='#')
                S[i1++]=S[i];
            else if(i1>0)
                i1--;
        }
        for(i=0,i2=0;i<T.length();i++){
            if(T[i]!='#')
                T[i2++]=T[i];
            else if(i2>0)
                i2--;
        }
       // cout<<i1<<' '<<i2<<endl;
        if(i1!=i2)
            return 0;
        for(i=0;i<i1;i++){
            //cout<<S[i]<<' '<<T[i]<<endl;
            if(S[i]!=T[i])
                return 0;
        }
        return 1;
    }
};