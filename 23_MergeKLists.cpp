#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
	struct MyListNode
	{
		ListNode *listnode;
		MyListNode(ListNode* node) : listnode(node) {}
		friend bool operator < (const MyListNode &node1, const MyListNode &node2);
	};

	friend bool operator < (const MyListNode &node1, const MyListNode &node2)
	{
		return node1.listnode->val < node2.listnode->val;	
	}

public:
	ListNode* mergeKLists(vector<ListNode*> &lists)
	{
		priority_queue<MyListNode> pq;
		ListNode *head;
		for (int i = 0; i < lists.size(); i++)
		{
			pq.push(MyListNode(lists[i]));	
		}
		while (pq.empty() != NULL)
		{
			MyListNode myNode = pq.top();
			myNode.listnode;
		}
	}
};