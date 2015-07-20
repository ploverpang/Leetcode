#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution 
{
public: 
	ListNode* mergeKLists(vector<ListNode*>& lists)
	{
		priority_queue<ListNode*,vector<ListNode*>, myComp> pq;
		for (int i = 0; i < lists.size(); i++)
		{
			if (lists[i] != NULL)
			{
				pq.push((lists[i]));
			}
		}
		ListNode *head = NULL;
		if (!pq.empty())
		{
			head = pq.top();
			pq.pop();
			if (head->next != NULL)
			{
				pq.push(head->next);
			}
		}
		ListNode *cur = head;
		
		while (!pq.empty())
		{
			cur->next = pq.top();
			cur = cur->next;
			pq.pop();
			if (cur->next != NULL)
			{
				pq.push(cur->next);
			}
		}
		return head;
	}

	struct myComp
	{
		bool operator()(const ListNode* node1, const ListNode* node2)
		{
			return node1->val > node2->val;
		}
	};
};


void printLists(ListNode *head)
{
	while(head)
	{
		cout << head->val << " ";
		head = head->next;
	}
	cout << endl;
}

/*
int main()
{
	ListNode one(1);
	ListNode two(2);
	ListNode three(3);
	ListNode four(4);
	ListNode five(5);
	ListNode six(6);

	one.next = &four;
	two.next = &five;
	three.next = &six;

	vector<ListNode*> lists;
	lists.push_back(&one);
	lists.push_back(&two);
	lists.push_back(&three);

	Solution sln;
	ListNode * result = sln.mergeKLists(lists);
	printLists(result);
	system("PAUSE");
	return 0;
}
*/