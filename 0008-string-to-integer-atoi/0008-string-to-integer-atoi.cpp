class Solution {
public:
    int myAtoi(string s) {
        int i=0;
        while(s[i]==' ') i++;
        bool pos = s[i] == '+';
        bool neg = s[i] == '-';
        pos == true ? i++:i;
        neg == true ? i++:i;
        double ans = 0;
        while(i<s.size() && s[i]>='0' && s[i]<='9'){
            ans = (ans*10) + (s[i]-'0');
            i++;
        }
        ans = neg ? -ans:ans;
        ans = (ans>INT_MAX) ? INT_MAX : ans;
        ans = (ans<INT_MIN) ? INT_MIN : ans;
        return ans;
    }
};