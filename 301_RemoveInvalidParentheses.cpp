#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

class Solution {
public:
	/*
    vector<string> removeInvalidParentheses(string s) {
    }

	void deleteLeft(string str, int , vector<string> &afterDelete)
	{
		
	}

	vector<string> processLeftUnbalance(const string &str, vector<string> &afterProcess)
	{
		int cnt = 0;
		int j = 0;
		int lastBalancedIdx = -1;
		for (; j < str.size(); j++)
		{
			if (str[j] == '(')
			{
				cnt++;
			}	
			else if(str[j] == ')')
			{
				cnt--;
				if (cnt == 0)
				{
					lastBalancedIdx = j;
				}
				if (cnt < 0)
				{
					deleteLeft(str, j, afterProcess);
				}
			}
			else
			{
				continue;
			}
		}

		if (j == str.size()-1)
		{
			if(cnt == 0)
			{
				return vecStr;
			}
			else if (cnt > 0)
			{
				for (int i = 0; i < vecStr.size(); i++)
				{
					for (int k = lastBalanceIdx; k < str.size(); k++)
					{
						
						
					}
				}
			}
			else
			{

			}
		}
	}
	*/
};

/*
void main()
{
	Solution sln;
	system("PAUSE");
}
*/