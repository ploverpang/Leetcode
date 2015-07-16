#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
	int removeDuplicates(vector<int> &nums)
	{
		int cnt = 1;
		if (nums.empty())
		{
			return 0;
		}
		if (nums.size() == 1)
		{
			return 1;
		}
		for (auto it = nums.begin()+1; it != nums.end() ;)
		{
			if (*it == *(it-1))
			{
				it = nums.erase(it);
			}	
			else
			{
				it++;
				cnt++;
			}
		}
		return cnt;
	}
};
