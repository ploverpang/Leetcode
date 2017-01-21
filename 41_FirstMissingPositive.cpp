#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
/*
		if (nums.empty())
		{
			return 1;
		}
		*/
		int maxNum = 0;
		int lastLeftOneNumMax = 0;
		int sumWhenLeftOneNum = 0;
		int sumNow = 0;
		int positiveCnt = 0;
		int remainNum = 0;

		for (int i = 0; i < nums.size(); i++)
		{
			if (nums[i] > 0)
			{
				sumNow += nums[i];
				positiveCnt++;
				if (nums[i] > maxNum)
				{
					maxNum = nums[i];
				} 
				remainNum = maxNum - positiveCnt;
				if (remainNum == 1)
				{
					sumWhenLeftOneNum = sumNow;	
					lastLeftOneNumMax = maxNum;
				}
			}
		}
		if (remainNum == 0)
		{
			return maxNum+1;
		}

		int total = 0;
		for (int i = 0; i <= lastLeftOneNumMax; i++)
		{
			total += i;	
		}
		return (total - sumWhenLeftOneNum);
        
    }
};

/*
int main()
{
	int testArr[] = {2};
	vector<int> testVec(testArr, testArr+sizeof(testArr)/sizeof(int));
	vector<int> vec2;

	Solution sln;
	cout << sln.firstMissingPositive(vec2) << endl;
	system("PAUSE");
	return 0;
}
*/