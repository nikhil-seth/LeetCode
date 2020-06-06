// 344. Reverse String
class Solution {
public:
    void reverseString(vector<char>& s){
        int i=0,j=s.size()-1,temp;
        while(i<j){
            temp=s[i];
            s[i]=s[j];
            s[j]=temp;
            i+=1;
            j-=1;
        }
    }
};
    