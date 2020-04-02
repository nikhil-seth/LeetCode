//202. Happy Number

class Solution {
public:
    bool isHappy(int n) {
        if(n==0)
            return 0;
        int x,y,z;
        x=n;
        y=0;
        while(x>0){
            y=y+(x%10)*(x%10);
            x/=10;
        }
     //   cout<<y<<endl;
        if(y==1)
            return 1;
        x=y;
        do{
            n=0;
            while(x>0){
                n=n+(x%10)*(x%10);
                x/=10;
            }
            x=n;
           // cout<<x<<endl;
        }while(x!=y && x!=4&& x!=1);
        if(x==y || x==4)
            return 0;
        return 1;
    }
};