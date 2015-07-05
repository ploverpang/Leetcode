#include <vector>
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;




class Solution {
public:

	struct TwoSum
	{
		int sum;
		int index1;
		int index2;
		TwoSum(int sum, int index1, int index2):sum(sum), index1(index1), index2(index2){};
	};

	static bool comp(TwoSum &a, TwoSum &b)
	{
		return (a.sum < b.sum);
	}

	bool notRepeat(TwoSum a, TwoSum b)
	{
		return (a.index1 != b.index1
			&& a.index1 != b.index2
			&& a.index2 != b.index1
			&& a.index2 != b.index2);
	}

	vector<int> sortTwoSum(vector<int> &nums, TwoSum a, TwoSum b)
	{
		vector<int> fourIndex(4);
		fourIndex[0]=nums[a.index1];
		fourIndex[1]=nums[a.index2];
		fourIndex[2]=nums[b.index1];
		fourIndex[3]=nums[b.index2];
		sort(fourIndex.begin(), fourIndex.end());
		return fourIndex;
	}

	  vector<vector<int>> fourSum(vector<int>& nums, int target) {
		vector<vector<int> > result;

		sort(nums.begin(), nums.end());

		vector<TwoSum> vecTwoSum;
		for (int i = 0; i < nums.size()-1; i++)
		{
			if (i != 0 && nums[i]==nums[i-1])
			{
				continue;
			}
			for (int j = i+1; j < nums.size(); j++)
			{
				if (j != i+1 && nums[j]==nums[j-1])
				{
					continue;
				}
				vecTwoSum.push_back(TwoSum(nums[i]+nums[j], i, j));
			}
		}

		sort(vecTwoSum.begin(), vecTwoSum.end(), &Solution::comp);
		set<vector<int>> result_set;
		for (int i = 0; i < vecTwoSum.size()-1; i++)
		{
			for (int j = i+1; j < vecTwoSum.size(); j++)
			{
				if (vecTwoSum[i].sum == (target-vecTwoSum[j].sum) && notRepeat(vecTwoSum[i], vecTwoSum[j]))
				{
					result_set.insert(sortTwoSum(nums, vecTwoSum[i], vecTwoSum[j]));
				}
			}
		}

		for (auto set_it = result_set.begin(); set_it != result_set.end(); set_it++)
		{
			result.push_back(*set_it);
		}
		return result;
	}



    vector<vector<int>> fourSumEasy(vector<int>& nums, int target) {
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
	auto resultEasy = sln.fourSumEasy(testCase, 0);
	cout << resultEasy.size() << endl;

	auto result = sln.fourSum(testCase, 0);
	cout << result.size() << endl;
	system("PAUSE");
	return 0;
}