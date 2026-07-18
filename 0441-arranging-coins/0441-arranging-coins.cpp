class Solution {
public:
    int arrangeCoins(int n) {
        // int mx;
        // int c=0;
        // while(n!=0){
        //     if(n%2!=0) mx=n/2+1;
        //     else mx=n/2;
        //     for(int i=mx;i>0;i--){
        //         n-=i;
        //         c++;
        //     }
        // }
        // return c;
        long long lo=1;
        long long hi=n;
        while(lo<=hi){
            long long k=lo+(hi-lo)/2;
            long long m=k*(k+1)/2;
            if(m==n)  return (int)k;
            else if(m>n)  hi=k-1;
            else lo=k+1;
        }
        return (int)hi;
    }
};