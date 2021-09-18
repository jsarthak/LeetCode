#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *prev;
    Node *next;
    Node *child;
};

Node *flatten(Node *head)
{
    if (head == NULL)
        return head;
    Node *current = head, *temp;
    while (current)
    {

        // check if current has child
        if (current->child)
        {
            // make a new next node and assign current -> next for later assigning
            Node *next = current->next;
            // store current child
            Node *child = current->child;
            current->next = child;
            child->prev = current;
            current->child = NULL;
            temp = current->next;

            if (next)
            {
                while (temp->next)
                {

                    temp = temp->next;
                }
                temp->next = next;
                next->prev = temp;
            }
        }

        current = current->next;
    }
    return head;
}
