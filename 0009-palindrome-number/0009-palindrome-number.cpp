class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        long long ans = 0;
        long long num = x;
        while(x!=0){
            int p = x%10;
            ans = ans*10+p;
            x=x/10;
        }
        return(ans==num);
    }
};