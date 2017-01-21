#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
		vector<vector<int> > result;
		if (nums.empty())
		{
			return result;
		}
		result.push_back(vector<int>() );
		vector<vector<int> > remainSet;
		remainSet.push_back(nums);
        process(remainSet, result);
		
		return result;
    }

	void process(vector<vector<int> > &remainSet, vector<vector<int> > &result)
	{
		if (remainSet.empty())
		{
			return;
		}

		vector<vector<int> > beforeProcessResult(result);
		vector<vector<int> > beforeProcessRemainSet(remainSet);
		result.clear();
		remainSet.clear();

		for (int i = 0; i < beforeProcessResult.size(); i++)
		{
			for (int j = 0; j < beforeProcessRemainSet[i].size(); j++)
			{
				beforeProcessResult[i].push_back(beforeProcessRemainSet[i][j]);
				result.push_back(beforeProcessResult[i]);
				beforeProcessResult[i].erase(beforeProcessResult[i].end()-1);

				vector<int> clearOneElemSet(beforeProcessRemainSet[i]);
				clearOneElemSet.erase(clearOneElemSet.begin()+j);
				if (!clearOneElemSet.empty())
				{
					remainSet.push_back(clearOneElemSet);
				}
			}
		}
		process(remainSet, result);
	}
};
/*
int main()
{
	int A_arr[] = {1,2,3};
	vector<int> A(A_arr, A_arr+sizeof(A_arr)/sizeof(int));
	Solution sln;
	auto result = sln.permute(A);
	for (int i = 0; i < result.size(); i++)
	{
		for (int j = 0; j < result[i].size(); j++)
		{
			cout << result[i][j] << " ";
		}
		cout << endl;
	}
	system("PAUSE");
	return 0;
}
*/
