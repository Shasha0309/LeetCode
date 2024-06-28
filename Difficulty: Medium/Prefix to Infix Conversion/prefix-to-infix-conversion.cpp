//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  bool operand(char x){
      switch(x){
          case '+':
          case '-':
          case '*':
          case '/':
          case '^':
          case '%':
          return true;
      }
      return false;
  }
    string preToInfix(string pre_exp) {
        // Write your code here
        stack<string> st;
        
        for(int i=pre_exp.length()-1;i>=0;i--){
            
            if(operand(pre_exp[i])){
                string op1 = st.top();
                st.pop();
                string op2 = st.top();
                st.pop();
            
            string temp = '(' + op1 + pre_exp[i] + op2 + ')';
            st.push(temp);
        }
        else{
            st.push(string(1,pre_exp[i]));
        }
    }
    return st.top();
    }
};

//{ Driver Code Starts.
int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        string prefix;
        cin >> prefix;

        Solution obj;
        cout << obj.preToInfix(prefix) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}

// } Driver Code Ends