// 43. Multiply Strings

class Solution {
public:
    string multiply(string num1, string num2){
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        int n=num1.length(),m=num2.length(),val;
        vector<int> v(n+m,0);
        for(int i=0;i<n;i+=1){
            for(int j=0;j<m;j+=1){
                val=(num1[i]-48)*(num2[j]-48);
                v[i+j+1]+=val%10;
                v[i+j]+=val/10;
            }
        }
        val=0;
        string ans;
        for(int i=n+m-1;i>=0;i-=1){
            v[i]+=val;
            val=v[i]/10;
            v[i]%=10;
        }
        if(val>0)
            ans.push_back(val+48);
        val=0;
        while(val<m+n && v[val]==0) val+=1;
        while(val<m+n)
            ans.push_back(v[val++]+48);
        if(ans.length()==0) return "0";
        return ans;
    }
};
