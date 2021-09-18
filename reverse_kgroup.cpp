// Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

// k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.

// You may not alter the values in the list's nodes, only nodes themselves may be changed.

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

ListNode *reverseKGroup(ListNode *head, int k)
{
    int len = 0;
    ListNode *current = head;
    while (current)
    {
        len++;
        current = current->next;
    }
    if (len < k)
    {
        return head;
    }

    ListNode *prevHead = head;
    ListNode *prev = NULL;
    ListNode *next;
    current = head;
    int i = 0;
    while (current && i < k)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
        i++;
    }
    prevHead->next = reverseKGroup(current, k);
    return prev;
}