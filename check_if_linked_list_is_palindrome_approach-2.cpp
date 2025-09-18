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
    // Utility: find the middle node of the list
    Node* findMiddle(Node* head) {
        Node* slow = head;
        Node* fast = head->next;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;  // slow ends up at mid
    }

    // Utility: reverse a linked list
    Node* reverseList(Node* head) {
        Node* prev = nullptr;
        Node* curr = head;

        while (curr != nullptr) {
            Node* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev;
    }

    // Function to check if the linked list is a palindrome
    bool isPalindrome(Node* head) {
        if (head == nullptr || head->next == nullptr) {
            return true;  // single node / empty list is always palindrome
        }

        // Step 1: find the middle of the list
        Node* mid = findMiddle(head);

        // Step 2: reverse the second half of the list
        Node* secondHalf = reverseList(mid->next);
        mid->next = secondHalf;

        // Step 3: compare both halves
        Node* p1 = head;
        Node* p2 = secondHalf;
        while (p2 != nullptr)
