// Given the head of a sorted linked list, delete all duplicates such that each element appears only once. Return the linked list sorted as well.

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
    if (head == NULL || head->next == NULL)
        return head;
    ListNode *prev = head, *current = head->next;
    while (current)
    {
        if (current->val == prev->val)
        {
            prev->next = current->next;
            delete current;
            current = prev->next;
        }
        else
        {
            current = current->next;
            prev = prev->next;
        }
    }
    return head;
}

int main()
{
    return 0;
}