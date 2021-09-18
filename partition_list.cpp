// Given the head of a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

// You should preserve the original relative order of the nodes in each of the two partitions.

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
ListNode *partition(ListNode *head, int x)
{

    ListNode *fake = new ListNode();
    ListNode *fake2 = new ListNode();
    ListNode *temp = fake;
    ListNode *temp2 = fake2;
    while (head)
    {
        if (head->val < x)
        {
            fake->next = head;
            fake = fake->next;
        }
        else
        {
            fake2->next = head;
            fake2 = fake2->next;
        }
        head = head->next;
    }

    fake2->next = NULL;
    fake->next = temp2->next;
    return temp->next;
}