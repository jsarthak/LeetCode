/*
	You are given two non-empty linked lists 
	representing two non-negative integers. 
	The digits are stored in reverse order, 
	and each of their nodes contains a single digit. 
	Add the two numbers and return the sum as a linked list.

	You may assume the two numbers do not contain any leading zero
	except the number 0 itself.
*/

struct ListNode
{
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
	// if both heads null return null
	if (l1 == nullptr && l2 == nullptr)
		return nullptr;

	// variable to store carry
	int carry = 0;

	// initialize the head of result list
	ListNode *result = new ListNode();
	ListNode *temp = result;

	// iterate while any of l1 or l2 is not null
	while (l1 || l2)
	{
		int sum = carry + (l1 ? l1->val : 0) + (l2 ? l2->val : 0);

		temp->val = sum % 10;
		carry = sum / 10;

		l1 = l1 ? l1->next : nullptr;
		l2 = l2 ? l2->next : nullptr;

		if (l1 || l2)
		{
			temp->next = new ListNode();
			temp = temp->next;
		}
	}

	if (carry)
	{
		temp->next = new ListNode();
		temp->next->val = carry;
	}

	return result;
}