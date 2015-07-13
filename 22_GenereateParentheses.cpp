#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
	vector<string> generateParenthesis(int n)
	{
		vector<string> result;
		result.push_back(string(""));
		return process(n, result);	
	}

	vector<string> process(int k, vector<string> vecStr) 
	{
		if (k == 0)
		{
			return vecStr;
		}

		vector<string> copyVecStr(vecStr);
		vecStr.clear();
		for (int i = 1; i <= k; i++)
		{
			vector<string> vecFromBefore = process(k-i, copyVecStr);
			string parenthesis = generateP(i);
			for (int j = 0; j < vecFromBefore.size(); j++)
			{
				string oneStr = vecFromBefore[j] + parenthesis; 
				vecStr.push_back(oneStr);
			}
		}
		return vecStr;
	}

	string generateP(int n)
	{
		string str;
		for (int i = 0; i < n; i++)
		{
			str += string(1, '(');	
		}
		for (int i = 0; i < n; i++)
		{
			str += string(1, ')');	
		}
		return str;
	}
};

int main()
{
	vector<string> result;
	Solution sln;
	result = sln.generateParenthesis(4);
	for (int i = 0; i < result.size(); i++)
	{
		cout << result[i] << endl;
	}
	system("PAUSE");
	return 0;
}