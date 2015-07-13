#include <iostream>
#include <string>
#include <map>
#include <stack>

using namespace std;

class Solution 
{
public:
	bool isValid(string s)
	{
		map<char, char> patten;
		patten.insert(make_pair('[', ']'));
		patten.insert(make_pair('(', ')'));
		patten.insert(make_pair('{', '}'));

		stack<char> cStack;
		for (int i = 0; i < s.length(); i++)
		{
			if (s[i] == '[' || s[i] == '(' || s[i] == '{')
			{
				cStack.push(s[i]);
			}
			else
			{
				if (!cStack.empty() && patten[cStack.top()] == s[i])
				{
					cStack.pop();
				}
				else
				{
					return false;
				}
			}
		}
		if (cStack.empty())
		{
			return true;
		}
		return false;
	}
};

/*
int main()
{
	Solution sln;
	cout << sln.isValid("}") << endl;
	system("PAUSE");
	return 0;
}
*/
