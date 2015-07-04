#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
		vector<vector<int> > result;
		sort(nums.begin(), nums.end());
		for (int i = 0; i < nums.size()-3; i++)
		{
			if (i != 0 && nums[i]==nums[i-1])
			{
				continue;
			}
			for (int j = i+1; j < nums.size()-2; j++)
			{
				if (j != i+1 && nums[j]==nums[j-1])
				{
					continue;
				}
				for (int k = j+1; k < nums.size()-1; k++)
				{
					if (k != j+1 && nums[k]==nums[k-1])
					{
						continue;
					}
					bool found = binary_search(nums.begin()+k+1, nums.end(), 
						target-(nums[i]+nums[j]+nums[k]));
					if(found)
					{
						vector<int> oneResult;
						oneResult.push_back(nums[i]);
						oneResult.push_back(nums[j]);
						oneResult.push_back(nums[k]);
						oneResult.push_back(
							target-(nums[i]+nums[j]+nums[k]));
						result.push_back(oneResult);
					}
				}
			}
		}
		return result;
    }
};

int main()
{
	int S[] = {1,0,-1,0,-2,2};
	vector<int> testCase(S, S+sizeof(S)/sizeof(int));
	Solution sln;
	auto result = sln.fourSum(testCase, 0);
	cout << result.size() << endl;
	system("PAUSE");
	return 0;
}