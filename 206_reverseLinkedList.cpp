#include <iostream>
#include <stack>

using namespace std;

//  Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

void printList1(ListNode* head)
{
	ListNode *p = head;
	while (p)
	{
		cout << p->val << " ";
		p=p->next;
	}
	cout << endl;
}
class Solution {
public:

	// 使用递归的反转链表
    ListNode* reverseList(ListNode* head) {
		ListNode * p = reverseNode(head, head);	
		p->next = NULL;
		return head;
    }

	ListNode* reverseNode(ListNode* cur, ListNode* &head)
	{
		if (cur->next == NULL)
		{
			head = cur;
			return cur;
		}
		reverseNode(cur->next, head)->next = cur;
		return cur;
	}

	//使用堆栈的反转链表
	ListNode* reverseListWithStack(ListNode* head)
	{
		if (head == NULL)
		{
			return head;
		}
		ListNode *p = head;
		stack<ListNode*> listStack;
		while (p)
		{
			listStack.push(p);
			p = p->next;
		}

		p = listStack.top();
		listStack.pop();
		head->next = NULL;
		head = p;

		while (!listStack.empty())
		{
			p->next = listStack.top();		
			p = listStack.top();
			listStack.pop();
		}
		return head;
	}

	//迭代实现的反转链表
    ListNode* reverseListNoRecurse(ListNode* head) {
		if (head == NULL)
		{
			return NULL;
		}
		if (head->next == NULL)
		{
			return head;
		}

		ListNode *before = head;
		ListNode *cur = head->next;

		bool isEnd=false;

		while (!isEnd)
		{
			ListNode *after = cur->next;
			isEnd = (after==NULL ? true : false);
			cur->next = before;

			if (!isEnd)
			{
				before = cur;
				cur = after;
			}
		}
		head->next = NULL;
		head = cur;
		return head;
	}
};

// 小程序，删除链表中的连续重复部分，比如aa->a; abb->ab; abba->aba;
void deleteRepeatInList(ListNode *head)
{
	if (head == NULL || head->next == NULL)
	{
		return;
	}
	ListNode* before = head;
	ListNode* cur = head->next;
	while (cur)
	{
		while (cur && cur->val == before->val)
		{
			cur = cur->next;
		}
		before->next = cur;
		before = cur;
		if(cur) cur = cur->next;
	}
}
/*
int main()
{
	ListNode* one = new ListNode(1);

	ListNode* two = new ListNode(2);
	ListNode* three = new ListNode(3);
	ListNode* four = new ListNode(4);

	one->next = two;
	two->next = three;
	three->next = four;

	printList1(one);
	Solution sln;
	//ListNode *p = sln.reverseListNoRecurse(one);
	//ListNode *p = sln.reverseListWithStack(one);
	ListNode *p = sln.reverseList(one);
	printList1(p);
	system("PAUSE");
	return 0;
}
*/