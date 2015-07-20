#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
		if(nums.empty())
		{
			return 0;
		}
        int length = nums.size();
		for (int i = 0; i < length;)
		{
			if (nums[i] == val)
			{
				swap(nums[length-1], nums[i]);
				length --;
			}
			else
			{
				 i++;
			}
		}
		nums.erase(nums.begin()+length, nums.end());
		return length;
    }
};

/*
int main()
{
	vector<int> test;
	test.push_back(1);
	test.push_back(2);
	test.push_back(2);
	test.push_back(3);

	Solution sln;
	int result = sln.removeElement(test, 2);
	for (auto num : test)
	{
		cout << num << endl;
	}
	cout << "Length is " << result << endl;
	system("PAUSE");
	return 0;
}
*/