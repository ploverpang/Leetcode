#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
		vector<int> result;
		int left = 0;
		int right = nums.size()-1;
		
		int onePos = -1;

		while(left <= right)
		{
			int middle = (left+right)/2;
			if (nums[middle] == target)
			{
				onePos = middle;	
				break;
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
		if (onePos == -1)
		{
			result.push_back(-1);
			result.push_back(-1);
		}
		else
		{
			result.push_back(findRange(nums, onePos, -1));
			result.push_back(findRange(nums, onePos, 1));
		}
		return result;
    }

	int findRange(vector<int> &nums, int start, int step)
	{
		int range = start;
		while (range >= 0 && range < nums.size() && nums[range] == nums[start])
		{
			range += step;
		}
		return range-step;
	}

	int searchInsert(vector<int>& nums, int target) {
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
		return left;
    }
};

int main()
{
	int arr[] = {5,7,8,10};	
	vector<int> vecArr(arr, arr+sizeof(arr)/sizeof(int));
	Solution sln;
	vector<int> searched = sln.searchRange(vecArr, 6);
	cout << searched[0] << " " << searched[1] << endl; 

	cout << sln.searchInsert(vecArr, 11) << endl;
	system("PAUSE");
	return 0;

}