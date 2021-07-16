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

ListNode *insertionSortList(ListNode *head)
{
    ListNode *A = head->next;
    if (!A)
        return head;
    while (A)
    {
        ListNode *B = head;
        while (A != B)
        {
            if (B->val > A->val)
            {
                int t = A->val;
                A->val = B->val;
                B->val = t;
            }
            B = B->next;
        }
        A = A->next;
    }
    return head;
}