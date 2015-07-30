#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
	    int right = nums.size()-1;

	    while(left <= right)
	    {
	    	int middle = (left+right)/2;
			if(target == nums[middle])
			{
				return middle;
			}
			if (nums[middle] < nums[left])
			{
				if (target < nums[middle])
				{
					right = middle-1;
				}
				else
				{
					if (target >= nums[left])
					{
						right = middle-1;
					}
					else
					{
						left = middle+1;
					}
				}
			}
			else
			{
				if (target > nums[middle])
				{
					left = middle+1;	
				}
				else
				{
					if (target < nums[left])
					{
						left = middle+1;
					}
					else
					{
						right = middle-1;
					}
				}
			}
		}
	    return -1;
	}
};
/*
int main()
{
	int arr[] = {5,1,3};
	vector<int> test(arr, arr+sizeof(arr)/sizeof(int));
	Solution sln;
	cout << sln.search(test, 5) << endl;
	system("PAUSE");
	return 0;
}
*/