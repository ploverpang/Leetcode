#include <iostream>

using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
	ListNode* mergeTwoSortedList(ListNode* l1, ListNode* l2)
	{
		ListNode* head, *cur;	
		if (l1==NULL && l2==NULL)
		{
			return NULL;
		}
		else if (l1==NULL)
		{
			return l2;
		}
		else if(l2 == NULL)
		{
			return l1;
		}

		if (l1->val < l2->val)
		{
			head = l1;
			cur = l1;
			l1 = l1->next;
		}
		else
		{
			head = l2;
			cur = l2;
			l2 = l2->next;
		}
		while (l1 != NULL && l2 != NULL)
		{
			if (l1->val < l2->val)
			{
				cur->next = l1;
				cur = l1;
				l1 = l1->next;
			}
			else
			{
				cur->next = l2;
				cur = l2;
				l2 = l2->next;
			}
		}
		if (l1 == NULL)
		{
			cur->next = l2;
		}
		if (l2 == NULL)
		{
			cur->next = l1;
		}
		return head;
	}
};

/*
int main()
{
	ListNode one(1);
	ListNode two(2);
	ListNode three(3);
	ListNode four(4);
	ListNode five(5);
	ListNode six(6);
	ListNode seven(7);
	ListNode eight(8);

	one.next = &three;
	three.next = &five;
	five.next = &seven;

	two.next = &four;
	four.next = &six;
	//six.next = &eight;

	Solution sln;
	ListNode* result = sln.mergeTwoSortedList(&one, &two);
	system("PAUSE");
	return 0;
}
*/