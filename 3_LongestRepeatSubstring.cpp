#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
		for (int i = s.length()/2; i > 0; i--)
		{
			int j = 0;
			while(j+i <= s.length())
			{
				string subs = s.substr(j, i);
				if (notHaveRepeatChar(subs))
				{
					if (s.find(subs)!=s.rfind(subs))
					{
						return i;
					}
				}
				j++;
			}
		}
    }

	bool notHaveRepeatChar(string s) {
		for (int i = 0; i < s.length(); i++)
		{
			if(s.find(s[i], i+1) != string::npos)
				return true;
		}
		return false;
	}
};

/*
int main()
{
	string a("1231");
	Solution sls;
	cout << sls.lengthOfLongestSubstring(a) << endl;
	system("PAUSE");
}
*/