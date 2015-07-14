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
    ListNode* swapPairs(ListNode* head) {
	    if(head == NULL || head->next == NULL)
	    {
	    	return head;
	    }
	    ListNode* nextNext = head->next->next;
	    ListNode* next = head->next;
	    head->next->next = head;
	    head->next = swapPairs(nextNext);
	    return next;
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

	one.next = &two;
	two.next = &three;
	three.next = &four;
	four.next = &five;
	five.next = &six;
	six.next = &seven;
	seven.next = &eight;

	Solution sln;
	ListNode *result = sln.swapPairs(&one);
	system("PAUSE");
	return 0;
}
*/