// You are given two non-empty linked lists representing two non-negative integers. The most significant digit comes first and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

// You may assume the two numbers do not contain any leading zero, except the number 0 itself.

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

ListNode *Reverse(ListNode *head)
{
    ListNode *current, *prev, *next;
    current = head;
    prev = NULL;
    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    ListNode *l1R = Reverse(l1);
    ListNode *l2R = Reverse(l2);
    ListNode *res = new ListNode(INT_MAX);
    ListNode *ans = res;
    int carry = 0;
    while (l1R || l2R)
    {

        int sum = (l1R ? l1R->val : 0) + (l2R ? l2R->val : 0) + carry;
        carry = sum / 10;
        sum = sum % 10;
        ListNode *temp = new ListNode(sum);
        res->next = temp;
        res = res->next;
        if (l1R)
            l1R = l1R->next;
        if (l2R)
            l2R = l2R->next;
    }

    if (carry)
    {
        ListNode *temp = new ListNode(carry);
        res->next = temp;
        res = res->next;
    }

    return Reverse(ans->next);
}