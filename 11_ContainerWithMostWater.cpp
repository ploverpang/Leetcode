#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class Solution {
public:
    int maxArea(vector<int> &height) {
		if (height.empty())
		{
			return 0;
		}

		int begin_index = 0;
		int end_index = height.size()-1;
		
		int maxArea = 0;
		while (begin_index != end_index)
		{
			int oneArea = Area(height, begin_index, end_index);
			if (oneArea > maxArea)
			{
				maxArea = oneArea;
			}
			if (height[begin_index] < height[end_index])
			{
				begin_index++;
			}
			else
			{
				end_index--;
			}
		}
		return maxArea;
    }

	int Area(vector<int> &height, int begin, int end)
	{
		assert(end > begin);
		return (end-begin)*min(height[begin], height[end]);
	}
};
/*
int main()
{
	Solution sln;
	int a[] ={1,2,3,3,4,5,1,1};
	//int a[] ={1,1};
	vector<int> test(a, a+sizeof(a)/sizeof(int));
	cout << sln.maxArea(test) << endl;
	system("PAUSE");
	return 0;
}
*/