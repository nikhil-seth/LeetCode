// 921. Minimum Add to Make Parentheses Valid

class Solution {
public:
    int minAddToMakeValid(string S){
        int ob=0,ans=0;
        for(int i=0;i<S.length();i++){
            if(S[i]=='(')
                ++ob;
            else{
                if(ob>0)
                    ob--;
                else
                    ans+=1;
            }
        }
        return ans+ob;
    }
};
