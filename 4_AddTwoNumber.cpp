#include <iostream>
#include <cassert>

using namespace std;
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
		int carry = 0;
		int tmp = l1->val + l2->val;
		if (tmp > 9)
		{
			carry = 1;
			tmp = tmp%10;
		}
		ListNode *l3 = new ListNode(tmp);
		ListNode *head = l3;

		while (l1->next != NULL && l2->next != NULL)
		{
			l1 = l1->next;
			l2 = l2->next;

			tmp = l1->val+l2->val+carry;
			if (tmp > 9)
			{
				tmp = tmp % 10;
				carry = 1;
			}
			else
			{
				carry = 0;
			}
			ListNode *tmp_node = new ListNode(tmp);
			l3->next = tmp_node;
			l3 = l3->next;
		}

		if(l1->next != NULL)
		{
			assert(l2->next == NULL);
			l1 = l1->next;
			l3->next = l1;
			while (l3->next != NULL && carry == 1)
			{
				l3 = l3->next;
				l3->val = l3->val + carry;
				if (l3->val == 10)
				{
					l3->val = 0;
					carry = 1;
				}
				else
				{
					carry = 0;
				}
			}
		}
		if (l2->next != NULL)
		{
			assert(l1->next == NULL);
			l2 = l2->next;
			l3->next = l2;
			while (l3->next != NULL && carry == 1)
			{
				l3 = l3->next;
				l3->val = l3->val + carry;
				if (l3->val == 10)
				{
					l3->val = 0;
					carry = 1;
				}
				else
				{
					carry = 0;
				}
			}		
		}
		
		if (carry == 1)
		{
			l3->next = new ListNode(1);
		}
		
		return head;
    }
};

ListNode* genereateList(int num)
{
	ListNode *p = new ListNode(num%10);
	ListNode *head = p;
	num = num/10;
	while(num)
	{
		p->next = new ListNode(num%10);
		num = num/10;
		p = p->next;
	}
	return head;
}

void printList(ListNode *p)
{
	while (p)
	{
		cout << p->val ;
		p = p->next;
	}
	cout << endl;
}

ListNode* reverseList(ListNode *p)
{
	if(p->next != NULL)
	{
		reverseList(p->next)->next = p;
		ListNode* tmp = p;
		p = p->next;
		return tmp;
	}
}
/*
int main()
{
	ListNode *l1 = genereateList(999);
	ListNode *l2 = genereateList(1);
	printList(l1);
	printList(l2);
	
	Solution sln;
	ListNode *result = sln.addTwoNumbers(l1,l2);
	printList(result);

	system("PAUSE");
	return 0;
}
*/