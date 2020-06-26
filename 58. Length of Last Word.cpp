// 58. Length of Last Word
class Solution {
public:
    int lengthOfLastWord(string s){
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        int i=s.length()-1;
        int j;
        while(i>=0 && s[i]==' ')
            i--;
        j=i;
        while(j>=0 && s[j]!=' ')
            j--;
        return (i-j);
    }
};
