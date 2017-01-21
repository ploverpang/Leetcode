#include <iostream>

struct LinkList
{
	int val;
	LinkList *pNext;
	LinkList(int _val) : val(_val), pNext(NULL) {};
};

void sortLinkList(LinkList *pHead)
{
	LinkList *p1, *p2;
	LinkList *p2Prev, *pLast;
	p1 = pHead->pNext;	  // to be insert
	p2 = pHead;  // sorted

	pLast = pHead;
	while (p1 != NULL)
	{
		p2 = pHead;
		p2Prev = pHead;

		while (p2 != p1)
		{
			if (p1->val > p2->val)
			{
				p2Prev = p2;
				p2 = p2->pNext;
			}
			else
				break;
		}
	
		if (pHead == p2) // insert in head
		{
			pLast->pNext = p1->pNext;
			p1->pNext = p2;
			pHead = p1;
			pLast = p2;

		}
		else if (p1 != p2) // need move
		{
			p2Prev->pNext = p1;
			pLast->pNext = p1->pNext;
			p1->pNext = p2;
			pLast = p1;
		}
		else
			pLast = p1;
		
		p1 = pLast->pNext;
	}
}

void printLinklist(LinkList *pHead)
{
	LinkList *p = pHead;
	while (p != NULL)
	{
		printf("%d -> ", p->val);
		p = p->pNext;
	}
	printf("\n");
}

int main()
{
	LinkList node1(1);
	LinkList node2(2);
	LinkList node3(3);
	LinkList node4(4);
	LinkList node5(5);

	node5.pNext = &node4;
	node4.pNext = &node3;
	node3.pNext = &node2;
	node2.pNext = &node1;

	LinkList *pHead = &node5;
	std::cout << "Before sorted" << std::endl;
	printLinklist(pHead);

	sortLinkList(pHead);
	std::cout << "After sorted" << std::endl;
	printLinklist(pHead);
	//node1.pNext = &node2;


	system("PAUSE");
	return 0;

}
