#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
		if (matrix.empty() || matrix[0].empty())
		{
			return;
		}

        vector<vector<int>> old(matrix);
		int row = matrix.size();
		int cols = matrix[0].size();
		matrix.resize(cols);

		for (int i = 0; i < cols; i++)
		{
			matrix[i].resize(row);
		}

		for (int i = 0; i < cols; i++)
		{
			for (int j = 0; j < row; j++)
			{
				matrix[i][j] = old[row-j-1][i];
			}
		}
    }
};

/*
int main()
{
	vector<vector<int> > data(3);
	int cnt= 0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cnt++;
			data[i].push_back(cnt);
		}
	}

	Solution sln;
	sln.rotate(data);
	for (int i = 0; i < data.size(); i++)
	{
		for (int j = 0; j < data[i].size(); j++)
		{
			cout << data[i][j] << " ";
		}
		cout << endl;
	}
	system("PAUSE");
	return 0;
}
*/	

	
