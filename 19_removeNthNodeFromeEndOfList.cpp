#include <iostream>

using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x) {}
};

class Solution
{
public:
	ListNode* removeNthFromEnd(ListNode* head, int n)
	{
		if (head==NULL)
			return NULL;
		/*
		if (head->next == NULL && n == 1)
		{
			return NULL;	
		}
		*/
		int k = 0;
		return processNode(head, NULL, head, k, n);
	}

	ListNode* processNode(ListNode *&head, ListNode *before, ListNode *cur, int &kFromEnd, int n)
	{
		if (cur == NULL)
		{
			return NULL;
		}	
		processNode(head, cur, cur->next, kFromEnd, n);
		kFromEnd++;
		cout << kFromEnd << endl;
		if (kFromEnd == n)
		{
			if (head == cur)
			{
				head = cur->next;
			}
			else
			{
				before->next = cur->next;
			}
			//delete cur;
			cur = NULL;
		}
		return head;
	}
};

/*
int main()
{
	ListNode node1(1);
	ListNode node2(2);
	ListNode node3(3);
	ListNode node4(4);

	node1.next = &node2;
	node2.next = &node3;
	node3.next = &node4;
	node4.next = NULL;

	Solution sln;
	sln.removeNthFromEnd(&node1, 2);
	system("PAUSE");
	return 0;
}
*/
