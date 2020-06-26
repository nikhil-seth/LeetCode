// 67. Add Binary

class Solution {
public:
    string addBinary(string a, string b){
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        // 1+1=10
        // 1+1+1=11
        // 1+0=1
        // 0 + 0 =0
        int i=a.length()-1,j=b.length()-1;
        string ans;
        int c=0;
        while(i>=0 && j>=0){
            if(a[i]+b[j]+c==99)
                c=1,ans.push_back('1');
            else if(a[i]+b[j]+c==98)
                c=1,ans.push_back('0');
            else if(a[i]+b[j]+c==97)
                c=0,ans.push_back('1');
            else
                ans.push_back('0');
            i-=1,j-=1;
        }
        while(i>=0){
            if(a[i]+c==50)
                c=1,ans.push_back('0');
            else if(a[i]+c==49)
                c=0,ans.push_back('1');
            else
                ans.push_back('0');
            i-=1;
        }
        while(j>=0){
            if(b[j]+c==50)
                c=1,ans.push_back('0');
            else if(b[j]+c==49)
                c=0,ans.push_back('1');
            else
                ans.push_back('0');
            j-=1;
        }
        if(c)
            ans.push_back('1');
        reverse(ans.begin(),ans.end());
        return ans;
    }
};