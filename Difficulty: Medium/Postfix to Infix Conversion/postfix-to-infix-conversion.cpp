//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
 /* bool operators(char c){
      switch(c){
          case '+':
          case '-':
          case '*':
          case '/':
          case '^':
          case '%':
          return true;
      }
      return false;
  }*/
    string postToInfix(string exp) {
        // Write your code here
        stack<string> st;
        
        for(char i : exp){
            if(isalpha(i)){
                st.push(string(1,i));
            }
            else{
                string op1 = st.top();
                st.pop();
                string op2 = st.top();
                st.pop();
                
                
                st.push('(' + op2 + i + op1 + ')');
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
        string postfix;
        cin >> postfix;
        // char marker; cin >> marker;

        Solution obj;
        cout << obj.postToInfix(postfix) << endl;

        // cout << "~\n";
    }
    fclose(stdout);

    return 0;
}

// } Driver Code Ends