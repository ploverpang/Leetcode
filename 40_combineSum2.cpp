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
			if(i != candidates.size()-1 && candidates[i+1] == candidates[i])
			{
				continue;
			}
			int newTarget = target-candidates[i];
			if (newTarget == 0)
			{
				//为了消除重复元素
				while (i>0 && candidates[i] == candidates[i-1])
				{
					i--;
				}
				result.push_back(vector<int>(1,candidates[i]));
				continue;
			}
			vector<int> newCandidate(candidates.begin(), candidates.begin()+i);

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
	int arr[] = {2,2,2};
	vector<int> testCase(arr,arr+sizeof(arr)/sizeof(int));

	Solution sln;
	vector<vector<int>> result = sln.combinationSum(testCase, 4);

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