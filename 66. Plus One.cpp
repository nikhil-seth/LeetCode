// 66. Plus One

class Solution {
public:
    vector<int> plusOne(vector<int>& digits){
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        int i=digits.size()-1;
        int c=1;
        while(i>=0){
            digits[i]+=c;
            if(digits[i]>9)
                digits[i]%=10,c=1;
            else
                c=0;
            i--;
        }
        if(c)
            digits.insert(digits.begin(),c);
        return digits;
    }
};
        