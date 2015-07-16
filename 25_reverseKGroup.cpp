#include <iostream>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
	ListNode *cur = head;
	int cnt = 0;
	while(cur && cnt < k)
	{
		cnt++;
		cur = cur->next;
	}
	if(cnt != k)
	{
		return head;
	}
	else
	{
		ListNode *result = reverseList(head, head, 1, k);
		result->next = reverseKGroup(cur, k);
		return head;
	}
    }

    ListNode* reverseList(ListNode* node, ListNode* &head, int cnt, int k)
    {
    	if(cnt == k)
	{
		head = node;	
		return head;
	}	
	reverseList(node->next, head, cnt+1, k)->next = node;
	return node;
    }
};

/*
void printList(ListNode *p)
{
	while (p)
	{
		cout << p->val ;
		p = p->next;
	}
	cout << endl;
}

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

	one.next = &two;
	two.next = &three;
	three.next = &four;
	four.next = &five;
	five.next = &six;
	six.next = &seven;
	seven.next = &eight;

	Solution sln;
	ListNode *result = sln.reverseKGroup(&one, 3);
	printList(result);
	system("PAUSE");
	return 0;
}
*/
