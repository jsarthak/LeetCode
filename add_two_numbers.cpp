/*
	You are given two non-empty linked lists 
	representing two non-negative integers. 
	The digits are stored in reverse order, 
	and each of their nodes contains a single digit. 
	Add the two numbers and return the sum as a linked list.

	You may assume the two numbers do not contain any leading zero
	except the number 0 itself.
*/

typedef struct ListNode{
	int val;
	struct ListNode *next;
} ListNode;

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2){
	// if both heads null return null
	if (l1 == NULL && l2 == NULL)
		return NULL;

	// variable to store carry
	int  carry = 0;

	// initialize the head of result list
	ListNode* result = new ListNode();
	ListNode* temp = result;

	// iterate while any of l1 or l2 is not null
	while (l1 || l2){
		int sum = carry + (l1?l1->val:0) + (l2?l2->val:0);
		
		temp -> val = sum%10;
        carry = sum/10;
		
        l1 = l1 ? l1 -> next: NULL;
        l2 = l2 ? l2 -> next : NULL;
        
        if (l1 || l2){
            temp -> next = new ListNode();
		    temp = temp -> next;
        }
	}

	if (carry){
		temp -> next = new ListNode();
		temp -> next -> val = carry;
	}

	return result;

}