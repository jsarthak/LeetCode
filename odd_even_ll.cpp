
// Given the head of a singly linked list, group all the nodes with odd indices together followed by the nodes with even indices, and return the reordered list.

// The first node is considered odd, and the second node is even, and so on.

// Note that the relative order inside both the even and odd groups should remain as it was in the input.

// You must solve the problem in O(1) extra space complexity and O(n) time complexity.

#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution
{
public:
    ListNode *oddEvenList(ListNode *head)
    {
        if (head == NULL || head->next == NULL || head->next->next == NULL)
            return head;
        ListNode *node1 = head;
        ListNode *node2 = head->next;
        ListNode *even = node2;
        while (node1 && node1->next && node2 && node2->next)
        {
            node1->next = node1->next->next;
            node2->next = node2->next->next;
            node1 = node1->next;
            node2 = node2->next;
        }

        if (node2)
        {
            node2->next = NULL;
        }
        if (node1)
        {
            node1->next = NULL;
        }
        node1 = head;
        while (node1->next)
        {
            node1 = node1->next;
        }
        node1->next = even;

        return head;
    }
};