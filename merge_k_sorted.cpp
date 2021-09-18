
// You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

// Merge all the linked-lists into one sorted linked-list and return it.
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
 ListNode* mergeList(ListNode* l1, ListNode* l2){
        ListNode* result = NULL;
        if (l1 == NULL) return l2;
        if (l2 == NULL) return l1;
        if (l1 -> val < l2 -> val){
            result = l1;
            result -> next = mergeList(l1 -> next, l2);
        } else {
            result = l2;
            result -> next = mergeList(l1, l2-> next);
        }
        return result;
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size()<1) return NULL;
        ListNode* first = lists[0];
        for(int i =1; i < lists.size();i++){
            first = mergeList(first, lists[i]);
        }
        return first;
    }