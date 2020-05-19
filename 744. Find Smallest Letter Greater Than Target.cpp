// 744. Find Smallest Letter Greater Than Target

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target){
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        int lo=0,hi=letters.size(),mid;
        while(lo<hi){
            mid=lo+(hi-lo)/2;
            if(letters[mid]<=target)
                lo=mid+1;
            else
                hi=mid;
        }
        if(letters[hi]<target)
            return letters[0];
        return letters[hi];
    }
};

        