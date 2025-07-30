class Solution {
public:
    int mySqrt(int x) {
      /*  if(x==0 || x==1) return x;
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
        return j;*/
         if (x == 0) return 0;
    int left = 1, right = x;
    while (left <= right) {
        long long mid = left + (right - left) / 2;
        if (mid * mid == x) return mid;
        else if (mid * mid < x) left = mid + 1;
        else right = mid - 1;
    }
    return right;
    }
};