#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
		if (haystack.size() < needle.size())
		{
			return -1;
		}
		if (haystack.empty() || needle.empty())
		{
			return 0;
		}

		vector<int> stepArray = getStepArray(needle);
		int start = 0;
		int cur = 0;

		while (start <= haystack.size()-needle.size())
		{
			while (start+cur < haystack.size() && cur < needle.size() && haystack[start+cur] == needle[cur])
			{
				cur++;
			}
			if (cur == needle.size())
			{
				return start;
			}
			else
			{
				start += stepArray[cur];
				cur = 0;
			}
		}
		return -1;
    }

	vector<int> prefixLength(const string &needle)
	{
		vector<int> prefixL(needle.size(), 0);
		int curL = 0;
		for (int i = 1; i < needle.size()-1; i++)
		{
			if (needle[curL] == needle[i])
			{
				curL++;
			}
			else
			{
				curL = 0;
			}
			prefixL[i+1] = curL;
		}
		return prefixL;
	}

	vector<int> getStepArray(const string &needle)
	{
		vector<int> prefixL = prefixLength(needle);
		prefixL[0] = 1;
		for (int i = 1; i < prefixL.size(); i++)
		{
			prefixL[i] = i - prefixL[i];
		}
		return prefixL;
	}
};

/*
int main()
{
	string src("a");
	string patten("a");
	Solution sln;
	int myResult = sln.strStr(src, patten);
	int stlResult = src.find(patten);

	system("PAUSE");
	return 0;
}
*/