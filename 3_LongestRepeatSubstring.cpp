#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
		string max_str;
		int maxStrLength = 0;
		for (int i = 0; i < s.length(); i++)
		{
			int j = max_str.find(s[i]);
			if (j == string::npos)
			{
				max_str += s[i];
				if (max_str.length() > maxStrLength)
				{
					maxStrLength = max_str.length();
				}
			}
			else
			{
				max_str = max_str.substr(j+1, max_str.length());
				max_str += s[i];
			}
		}
		return maxStrLength;
    }
};

int main()
{
	string a("123214311");
	Solution sls;
	cout << sls.lengthOfLongestSubstring(a) << endl;
	system("PAUSE");
}