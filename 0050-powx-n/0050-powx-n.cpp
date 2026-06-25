class Solution {
public:
    double myPow(double x, int n) {
        if(n==0) 1.0;
        if(x==0) 0.0;
        if(x==1) 1.0;

        long binform=n;
        if(n<0){
            x=1/x;
            binform=-binform;
        }

        double ans=1;
        while(binform>0){
            if(binform%2==1){
                ans*=x;
            }
            x*=x;
            binform/=2;
        }

        return ans;
    }
};