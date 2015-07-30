#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
		if(nums.size() < 2)
		{
			return;
		}

		int i = nums.size()-1;
		for (; i >0 ; i--)
		{
			if(nums[i] > nums[i-1])
			{
				int j = i;
				while (j < nums.size() && nums[j] > nums[i-1])
				{
					j++;
				}
				swap(nums[i-1], nums[j-1]);
				reverseElement(nums, i, nums.size()-1);
				break;
			}	
		}

		if (i == 0)
		{
			reverseElement(nums, 0, nums.size()-1);
		}
    }

	void reverseElement(vector<int> &nums, int p, int q)
	{
		while (p<q)
		{
			swap(nums[p], nums[q]);
			p++;
			q--;
		}
	}
};

/*
int main()
{
	int arr[] = {1,3,2,2,0};
	vector<int> data(arr, arr+(sizeof(arr)/sizeof(int)));
	Solution sln;
	sln.nextPermutation(data);

	for (int i = 0; i < data.size(); i++)
	{
		cout << data[i] << " ";
	}
	cout << endl;
	system("PAUSE");
	return 0;
}
*/