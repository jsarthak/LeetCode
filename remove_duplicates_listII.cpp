// Given the head of a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list. Return the linked list sorted as well.

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

ListNode *deleteDuplicates(ListNode *head)
{
    ListNode *newHead = new ListNode(0, head);
    ListNode *prev = newHead;
    while (head)
    {
        if (head->next && head->next->val == head->val)
        {
            while (head->next && head->next->val == head->val)
            {
                head = head->next;
            }
            prev->next = head->next;
        }
        else
        {
            prev = head;
        }
        head = head->next;
    }
    return newHead->next;
}