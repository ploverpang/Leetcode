#include <iostream>
#include <string>
#include <cassert>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
		int max_cnt = -128;
		string max_string;
		for (int i = 0; i < s.length(); i++)
		{
			int j = 0;
			int cnt = -1;
			while(i-j>=0 && i+j < s.length())
			{
				if (s[i-j] != s[i+j])
				{
					cnt = -1;
					break;
				}
				else 
				{
					cnt +=2;
					if(cnt > max_cnt)
					{
						max_cnt = cnt;
						max_string = s.substr(i-j, i+j+1);
						assert(s[i-j]==s[i+j]);
					}
					j++;
				}
			}
		}

		for (int i = 0; i < s.length(); i++)
		{
			int j = 0;
			int cnt = 0;
			while(i-j>=0 && i+j+1 < s.length())
			{
				if (s[i-j] != s[i+j+1])
				{
					cnt = 0;
					break;
				}else
				{
					cnt +=2;
					if(cnt > max_cnt)
					{
						max_cnt = cnt;
						max_string = s.substr(i-j, i+j+2);
						assert(s[i-j]==s[i+j+1]);
					}
					j++;
				}
			}
		}
		return max_string;
	}
};

/*
int main()
{
	//string test("1");
	string test("1234321111432155123411");
	Solution sln;
	string result = sln.longestPalindrome(test);
	//cout << result << endl;
	return 0;
}
*/