#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
		if (height.empty())
		{
			return 0;
		}      

		int water = 0;
		int i = 0;
		while(i<height.size()-1)
		{
			int j = i+1;
			int max_index = -1;
			int max_height = -1;
			int stone_accumulation = 0; //记录找到一个积水区间中，石头所占的体积。
			int stone_in_max_range = 0; //[i,max_index]区间中的石头数量
			while(j < height.size() && height[i] > height[j])
			{
				if (height[j] > max_height)
				{
					max_index = j;
					max_height = height[j];
					stone_in_max_range = stone_accumulation;
				}
				stone_accumulation += height[j];
				j++;
			}
			if (j == height.size())
			{
				water += (max_index-i-1)*max_height-stone_in_max_range;
				i = max_index;
			}
			else
			{
				water += (j-i-1)*height[i]-stone_accumulation;
				i = j;
			}
		}
		return water;
	}
};
/*
int main()
{
	//int height_arr[] = {0,1,0,2,1,0,1,3,2,1,2,1};
	int height_arr[] = {6,5,4,3,2,1,0,1};
	vector<int> height(height_arr, height_arr+sizeof(height_arr)/sizeof(int));
	Solution sln;
	cout << sln.trap(height) << endl;
	system("PAUSE");
	return 0;
}
*/