//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};

void printList(Node* node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << "\n";
}

void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        delete temp;
    }
}


// } Driver Code Ends
/*

  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution {
  public:
    // Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node* head) {

        // Add code here
        Node* zerohe = new Node(-1);
        Node* onehe = new Node(-1);
        Node* twohe = new Node(-1);
        
        Node* zero = zerohe;
        Node* one = onehe;
        Node* two = twohe;
        
        Node* temp = head;
        while(temp!=NULL){
            if(temp->data==2){
                two->next = temp;
                two=two->next;
            }
            else if(temp->data==1){
                one->next=temp;
                one=one->next;
            }
            else{
                zero->next=temp;
                zero=zero->next;
            }
            temp=temp->next;
        }
        zero->next = (onehe->next)?(onehe->next):(twohe->next);
        one->next = twohe->next;
        two->next = NULL;
        Node* renode = zerohe->next;
        delete(zerohe);
        delete(onehe);
        delete(twohe);
        
        return renode;
    }
};


//{ Driver Code Starts.

// Driver program to test above functions
int main() {
    int t, k;
    cin >> t;
    cin.ignore(); // Ignore the newline character after t

    while (t--) {
        string input;
        getline(cin, input); // Read the entire line for the array elements

        stringstream ss(input);
        Node *head = nullptr, *tail = nullptr;
        int x;

        if (ss >> x) {
            head = new Node(x);
            tail = head;

            while (ss >> x) {
                tail->next = new Node(x);
                tail = tail->next;
            }

            // Link the last node to the head if k is 1 to make it circular
            if (k == 1) {
                tail->next = head;
            }
        }

        Solution ob;
        Node* newHead = ob.segregate(head);
        printList(newHead);
    }

    return 0;
}
// } Driver Code Ends