#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <queue>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;

		if (root == NULL)
		{
			return result;
		}

		stack<TreeNode*> rootStack;
		map<TreeNode*, int> visited;

		TreeNode *curs = root; 
		rootStack.push(root);

		while (!rootStack.empty())
		{
			//while (curs->left != NULL)
			if(curs->left != NULL && visited.count(curs->left) == 0)
			{
				curs = curs->left; 
				rootStack.push(curs);
			}
			else if (curs->right != NULL && visited.count(curs->right) == 0)
			{
				curs = curs->right;
				rootStack.push(curs);
			}
			else
			{
				visited[rootStack.top()]++;
				result.push_back(rootStack.top()->val);
				rootStack.pop();
				if (!rootStack.empty())
				{
					curs = rootStack.top();
				}
			}
		}
		return result;
    }

	vector<int> preorderTraversal(TreeNode* root) {
		vector<int> result;
		if (root == NULL)
		{
			return result;
		}

		stack<TreeNode*> rootStack;
		map<TreeNode*, int> visited;

		TreeNode *curs = root; 
		rootStack.push(root);

		while (!rootStack.empty())
		{
			if (visited.count(curs) == 0)
			{
				result.push_back(curs->val);
				visited[curs]++;
				rootStack.push(curs);
			}
			if (curs->left && visited.count(curs->left)==0)
			{
				curs = curs->left;
			}
			else if(curs->right && visited.count(curs->right)== 0)
			{
				curs = curs->right;
			}
			else
			{
				curs = rootStack.top();
				rootStack.pop();
			}
		}
		return result;
    }
};

/*
int main()
{
	TreeNode *tree = new TreeNode(1);
	TreeNode *leftNode = new TreeNode(2);
	TreeNode *rightNode = new TreeNode(3);
	tree->left = leftNode;
	tree->right = rightNode;

	TreeNode *one= new TreeNode(1);
	TreeNode *two= new TreeNode(2);
	TreeNode *three= new TreeNode(3);
	TreeNode *four= new TreeNode(4);
	one->left = two;
	one->right= three;
	two->left = four;
	Solution sln;
	//vector<int> result = sln.postorderTraversal(tree);
	vector<int> result = sln.preorderTraversal(one);
	for (int i = 0; i < result.size(); i++)
	{
		cout << result[i] << endl;
	}
	system("PAUSE");
	return 0;
}
*/