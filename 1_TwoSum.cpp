#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> result(2);
		vector<int> cloned(nums);

		sort(cloned.begin(), cloned.end());
		int first_num;
		int second_num;
		for (int i = 0; i < cloned.size()-1; i++)
		{
			if(binary_search(cloned.begin()+i+1, cloned.end(), target-cloned[i]))
			{
				first_num = cloned[i];	
				second_num = target-cloned[i]; 
				break;
			}
		}

		vector<int>::iterator it = find(nums.begin(), nums.end(), first_num);
		result[0] = it-nums.begin()+1;

		if (first_num == second_num)
		{
			it = find(it+1, nums.end(), second_num);
		}
		else
		{
			it = find(nums.begin(), nums.end(), second_num);
		}
		result[1] = it-nums.begin()+1;

		if (result[0] > result[1])
		{
			int tmp = result[0];
			result[0] = result[1];
			result[1] = tmp;
		}

		return result;
	}
};

/*
int main()
{
	int a[] = {3,2,4};
	vector<int> test(a, a+sizeof(a)/sizeof(int));
	Solution sln;
	vector<int> result =  sln.twoSum(test, 6);
	cout << result[0] << " " << result[1] << endl;
	system("PAUSE");
	return 0;
}
*/