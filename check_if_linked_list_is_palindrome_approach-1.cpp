/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to check whether the linked list is palindrome.
    bool isPalindrome(Node *head) {
        vector<int> values;

        // Step 1: Store list elements in a vector
        for (Node* temp = head; temp != nullptr; temp = temp->next) {
            values.push_back(temp->data);
        }

        // Step 2: Use two-pointer technique to check palindrome
        int i = 0, j = values.size() - 1;
        while (i < j) {
            if (values[i] != values[j]) {
                return false;
            }
            i++;
            j--;
        }

        return true;
    }
};
