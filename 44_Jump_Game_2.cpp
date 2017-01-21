#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
		if (nums.empty())
		{
			return 0;
		}
		vector<int> jump_record(nums.size(), INT_MAX);
		jump_record[nums.size()-1] = 0;

		for(int i = nums.size()-2; i>=0; i--)
		{
			for (int j = i+1; j < nums.size(); j++)
			{
				if ((j-i < jump_record[i]) && jump_record[j]+1 < jump_record[i])
				{
					jump_record[i] = jump_record[j]+1;
				}
			}
		}

		return jump_record[0];
    }
};
/*
int main()
{
	int A_arr[] = {1,2,3,4,5};
	vector<int> A(A_arr, A_arr+sizeof(A_arr)/sizeof(int));
	Solution sln;
	cout << sln.jump(A) << endl;
	system("PAUSE");
	return 0;
}
*/