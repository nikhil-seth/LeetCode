// 264. Ugly Number II

class Solution {
public:
    int nthUglyNumber(int n){
       // ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        vector<int> v;
        v.push_back(1);
        int i2=0,i3=0,i5=0;
        while(v.size()<n){
            int mval=min(v[i2]*2,min(v[i3]*3,v[i5]*5));
            if(v[i2]*2==mval) i2+=1;
            if(v[i3]*3==mval) i3+=1;
            if(v[i5]*5==mval) i5+=1;
            v.push_back(mval);
        }
        return v.back();
    }
};
