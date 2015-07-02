#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
 string longestCommonPrefix(vector<string>& strs) {
    int begin_index = 0;
    int minCommonLength = minStrLength(strs);
    if (minCommonLength == 0)
    {
      return string("");
    }

	while(begin_index < minCommonLength)
    {
		if (isSameLetter(strs, begin_index))
		{
			begin_index++;
		}
		else
			break;
    }
	string prefix = strs[0].substr(0, begin_index);
    return prefix;
  }
private:
  bool isSameLetter(vector<string> &strs, size_t index)
  {
    bool same = true;
    for (size_t i = 0; i != strs.size()-1; i++)
    {
      same = same & (strs[i][index]==strs[i+1][index]);
      if (!same)
      {
        break;
      }
    }
    return same;
  }

  size_t minStrLength(vector<string> &strs)
  {
	  if (strs.empty())
	  {
		  return 0;
	  }
    size_t minLength = strs[0].length();
    for (size_t i=0; i !=strs.size(); i++)
    {
      if (strs[i].length() < minLength)
      {
        minLength = strs[i].length();
      }
    }
    return minLength;
  }
};
/*
int main()
{
	vector<string> testStr;
	testStr.push_back("abc");
	testStr.push_back("abdcccc");
	testStr.push_back("abcdccc");

	Solution sln;
	cout << sln.longestCommonPrefix(testStr) << endl;
	system("PAUSE");
	return 0;
}
*/