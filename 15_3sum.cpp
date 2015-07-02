#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution 
{
public:
	vector<vector<int> > threeSum(vector<int> &nums)
	{
		vector<vector<int> > result;
		std::sort(nums.begin(), nums.end());
		if (nums.size() <3)
		{
			return result;
		}

		for (int i = 0; i < nums.size()-2; i++)
		{
			if (i!=0 && nums[i-1] == nums[i])
			{
				continue;
			}
			for (int j = i+1; j < nums.size()-1; j++)
			{
				if (j!=i+1 && nums[j-1]==nums[j])
				{
					continue;
				}
				bool founded = std::binary_search(nums.begin()+j+1, nums.end(), 0-nums[i]-nums[j]);
				if (founded)
				{
					vector<int> oneTriple(3);
					oneTriple[0] = nums[i];
					oneTriple[1] = nums[j];
					oneTriple[2] = 0-nums[i]-nums[j];
					result.push_back(oneTriple);
				}
			}
		}
		return result;
	}

};

/*
void main()
{
	Solution sln;
	vector<int> array;
	array.push_back(0);
	array.push_back(0);
	array.push_back(0);
	array.push_back(0);
	array.push_back(-1);
	array.push_back(-1);
	array.push_back(1);
	array.push_back(1);

	vector<vector<int> > result = sln.threeSum(array);
	for (int i = 0; i < result.size(); i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << result[i][j] << " ";
		}
		cout << endl;	
	}
	system("PAUSE");
}
*/


