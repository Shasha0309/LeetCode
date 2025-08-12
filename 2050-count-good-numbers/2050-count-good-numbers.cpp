class Solution {
    
public:
const int MOD = 1e9+7;

long long sol(long long base,long long exp){
 long long result = 1;
 base %= MOD;
 while(exp>0){
    if(exp%2==0){
        base=(base*base)%MOD;
        exp=exp/2;
    }
    else{
        result=(result*base)%MOD;
        exp--;
    }
 }
 return result;
}
    int countGoodNumbers(long long n) {
        long long evens = (n+1)/2;
        long long odds = n/2;
        long long ans1 = sol(5,evens);
        long long ans2 = sol(4,odds);
        return (ans1*ans2) % MOD;
    }
};