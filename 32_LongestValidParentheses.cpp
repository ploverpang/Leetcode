#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
		return 0;
	}
	 
	//O(n^2)
    int longestValidParenthesesStupid(string s) {
		vector<vector<pair<int, int>> > table(s.size());
		for (int i = 0; i < table.size(); i++)
		{
			for (int j = 0; j < s.size(); j++)
			{
				table[i].push_back(make_pair(0,0));
			}
		}

		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == '(')
			{
				table[i][i].first = 1;
			}
			else
			{
				table[i][i].second = 1;
			}
		}

		int maxLength = 0;
		for (int i = 0; i < s.size(); i++)
		{
			for (int j = i+1; j < s.size(); j++)
			{
				if (s[j] == '(')
				{
					table[i][j].first = table[i][j-1].first+1;
					table[i][j].second= table[i][j-1].second;
				}
				else
				{
					table[i][j].first = table[i][j-1].first;
					table[i][j].second= table[i][j-1].second+1;

				}
				if (table[i][j].first == table[i][j].second && table[i][j].first > maxLength)
				{
					maxLength = table[i][j].first;
				}
			}
		}
		return maxLength*2;
    }
};

/*
int main()
{
	string s("");
	Solution sln;
	cout << sln.longestValidParentheses(s) << endl;
	system("PAUSE");
	return 0;
}
*/