class Solution {
public:
    int mySqrt(int x) {
        if(x==0 || x==1) return x;
        int i=1;
        int j=x/2;
       // int ans = 0;
        while(i<=j){
            long long mid = i+(j-i)/2;
            if(mid*mid==x) return mid;
             if(mid*mid>x){
                j=mid-1;
            }
            else{
                i=mid+1;
               // ans=mid;
            }
        }
        return j;
    }
};