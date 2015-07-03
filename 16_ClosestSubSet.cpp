#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
		sort(nums.begin(), nums.end());
        int distance = 0;

		while (1)
		{
			if(findSubSet(nums, target+distance))
				return target+distance;
			if(findSubSet(nums, target-distance))
				return target-distance;
			distance++;
		}
    }

	bool findSubSet(vector<int>& nums, int target)
	{
		for (int i = 0; i < nums.size(); i++)
		{
			for (int j = i+1; j < nums.size() ; j++)
			{
				if(binary_search(nums.begin()+j+1, nums.end(), target-(nums[i]+nums[j])))
					return true;
			}
		}	
		return false;
	}
};
/*
int main()
{
	int a[] = {-1,2,1,-4};
	vector<int> S(a, a+sizeof(a)/sizeof(int));
	Solution sln;
	cout << sln.threeSumClosest(S, 1) << endl;
	system("PAUSE");
	return 0;
}
*/
