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
		result.push_back("");
		vector<pair<int, int>> leftAndRightNum;
		leftAndRightNum.push_back(make_pair(0,0));
		for (int k = 0; k < 2*n; k++)
		{
			vector<string> copyResult(result);
			vector<pair<int, int>> copyLR(leftAndRightNum);
			result.clear();
			leftAndRightNum.clear();

			for (int i = 0; i < copyResult.size(); i++)
			{
				if (copyLR[i].first < n)
				{
					result.push_back(copyResult[i]+"(");
					leftAndRightNum.push_back(make_pair(copyLR[i].first+1, copyLR[i].second));
				}

				if (copyLR[i].first > copyLR[i].second)
				{
					result.push_back(copyResult[i]+")");
					leftAndRightNum.push_back(make_pair(copyLR[i].first, copyLR[i].second+1));
				}	
			}
		}
		return result;
	}

	vector<string> generateParenthesis1(int n)
	{
		vector<string> result;
		result.push_back(string(""));
		return process(result, n, n);	
	}

	vector<string> process(vector<string> &vecStr, int left, int right) 
	{
		if (left == 0 && right == 0)
		{
			return vecStr;
		}
		
		vector<string> vecStrCopy(vecStr);
		vector<string> processResult;
		if (left > 0)
		{
			vector<string> leftBefore = process(vecStrCopy, left-1, right);
			for (int i = 0; i < leftBefore.size(); i++)
			{
				leftBefore[i] += "(";	
				processResult.push_back(leftBefore[i]);
			}
		}
		if (right > left && right > 0)
		{
			vector<string> rightBefore = process(vecStrCopy, left, right-1);
			for (int i = 0; i < rightBefore.size(); i++)
			{
				rightBefore[i] += ")";	
				processResult.push_back(rightBefore[i]);
			}
		}
		vecStr.swap(processResult);
		return processResult;
	}

};
/*
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
*/