// 556. Next Greater Element III

class Solution {
public:
    int nextGreaterElement(int n) {
        string s;
        if(!n) return n;
        int x=n;
        while(x){
            s.push_back(48+x%10);
            x/=10;
        }
        reverse(s.begin(),s.end());
        int i=s.length()-1;
        while(i>0 && s[i-1]>=s[i])
            i-=1;
        if(i==0)
            return -1;
        i-=1;
        int j=i+1;
        while(j<s.length() && s[j]>s[i])
            j+=1;
        j-=1;
        swap(s[i],s[j]);
        sort(s.begin()+i+1,s.end());
        n=0;
        i=0;
        long long ans=0;
        while(i<s.length())
            ans=ans*10+(s[i++]-48);
        if(ans>INT_MAX) return -1;
        return ans;
    }
};

            