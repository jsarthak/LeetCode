

// You are given the head of a singly linked-list. The list can be represented as:

// L0 → L1 → … → Ln - 1 → Ln
// Reorder the list to be on the following form:

// L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
// You may not modify the values in the list's nodes. Only nodes themselves may be changed.
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
    void reorderList(ListNode *head)
    {
        stack<ListNode *> s;
        ListNode *temp;
        ListNode *current = head;
        while (current)
        {
            s.push(current);
            current = current->next;
        }
        current = head;
        while (current)
        {
            temp = current->next;
            if (current != s.top())
            {
                current->next = s.top();
                s.pop();
                current->next->next = current->next != temp ? temp : NULL;
                current = current->next->next;
            }
            else
            {
                current->next = NULL;
                break;
            }
        }
    }
};