#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		sort(candidates.begin(), candidates.end());
		return process(candidates,target);
	}

    vector<vector<int>> process(vector<int>& candidates, int target) {
		vector<vector<int> > result;
		if (candidates.empty() || target < 0)
		{
			return result;
		}    

		
		for (int i = candidates.size()-1; i >= 0; i--)
		{
			int newTarget = target-candidates[i];
			if (newTarget == 0)
			{
				result.push_back(vector<int>(1,candidates[i]));
				continue;
			}
			
			int pos = min(searchInsert(candidates, newTarget), i);
			vector<int> newCandidate(candidates.begin(), candidates.begin()+(pos+1));

			vector<vector<int>> newResult = process(newCandidate, newTarget);

			if (!newResult.empty())
			{
				for (int j = 0; j < newResult.size(); j++)
				{
					newResult[j].push_back(candidates[i]);
					result.push_back(newResult[j]);
				}
			}
		}
		return result;
    }

	int searchInsert(vector<int> &nums, int target)
	{
		int left = 0;
		int right = nums.size()-1;
		
		while(left <= right)
		{
			int middle = (left+right)/2;
			if (nums[middle] == target)
			{
				return middle;
			}
			
			if (nums[middle] < target)
			{
				left = middle +1;
			}
			else
			{
				right = middle - 1;
			}
		}
		return right;
	}
};

/*
int main()
{
	int arr[] = {1,2,3,6,7};
	vector<int> testCase(arr,arr+sizeof(arr)/sizeof(int));

	Solution sln;
	vector<vector<int>> result = sln.combinationSum(testCase, 8);

	for (int i = 0; i < result.size(); i++)
	{
		for (int j = 0; j < result[i].size(); j++)
		{
			cout << result[i][j] << " ";
		}
		cout << endl;
	}
	system("PAUSE");
	return 0;
}
*/