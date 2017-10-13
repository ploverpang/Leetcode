#include <iostream>
#include <vector>
#include <assert.h>

using namespace std;

 /* Definition for singly-linked list.*/
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || k == 0)
            return head;

        int l = 1;
        ListNode *p = head;
        ListNode *p_k= NULL;
        ListNode *plast = NULL;
        while(p->next)
        {
            l++;
            p = p->next;
        }
        //cout << "ll: " << l << endl;

        plast = p;

        k = k % l;
        if(k == 0)
            return head;
        else
        {
            k = l - k;
            p = head;
            int i = 0;
            while(p->next)
            {
                i++;
                if(i == k)
                {
                    p_k = p;
                    break;
                }
                p = p->next;
            }
        }

        plast->next = head;
        head = p_k->next;
        p_k->next = NULL;

        return head;
    }
};

int main()
{
    vector<ListNode> lst = {ListNode(0),
    ListNode(1),ListNode(2),ListNode(3), ListNode(4)};
    for(int i=0; i<lst.size()-1; i++)
    {
        lst[i].next = &lst[i+1];
    }

    ListNode *head  = &lst[0];

    auto print_lst = [](ListNode *head){
        ListNode *p = head;
        while(p)
        {
            cout << p->val << "->";
            p = p->next;
        }
        cout << "NULL" << endl;
    };

    print_lst(head);

    Solution sln;
    head = sln.rotateRight(head, 2);

    print_lst(head);
    return 0;
}
