class Solution {
public:
    int reverse(int x) {
        int rev = 0;
        while(x){
            rev = (rev*10)+(x%10);
            x/=10;
        }
        return rev;
    }
};