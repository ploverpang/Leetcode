#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
	vector<vector<string>> solveNQueens(int n) {
		vector<vector<int>> lut = make_lut(n);
		


	}

	bool solve_recurse(const int n, const vector<vector<int>> &every_elem_lut, vector<int> &cur_lut, stack<int> &cur_loc, vector<vector<int>> &result)
	{
		if (cur_loc.empty())
		{
			return true;
		}
		if (cur_loc.top() == n*n-1)
		{
			update_lut(cur_loc.top(), cur_lut, false);
			cur_loc.pop();
			update_lut(cur_loc.top(), cur_lut, false);
			int top = cur_loc.top();
			cur_loc.pop();
			if (top != n*n - 1)
			{
				cur_loc.push(top + 1);
			}
		}

	
	}

	void update_lut (const int n, vector<int> &lut, bool add)
	{
	
	}


	vector<vector<int>> make_lut(int n)
	{
		vector<vector<int> > lut(n*n);
		for (size_t i = 0; i < n*n; i++)
		{
			lut[i].resize(n*n, 0);
			lut[i][i] = 1;
			int cur = i;
			while (cur - n >= 0) //up
			{
				cur -= n;
				lut[i][cur] = 1;
			}
			cur = i;
			while (cur + n <= n*n-1) // down
			{
				cur += n;
				lut[i][cur] = 1;
			}
			cur = i;
			while (cur - 1 >= i*n) //left
			{
				cur -= 1;
				lut[i][cur] = 1;
			}
			cur = i;
			while (cur+1 <= (i+1)*n-1) // right
			{
				cur += 1;
				lut[i][cur] = 1;
			}
			cur = i;
			while(cur%n < (n-1) && cur/n < (n-1)) // right-down
			{
				cur += (n+1);
				lut[i][cur] = 1;
			}
			cur = i;
			while (cur%n > 0 && cur/n < (n-1)) // left-down
			{
				cur += (n-1);
				lut[i][cur] = 1;
			}
			cur = i;
			while (cur%n < (n - 1) && cur / n > 0) //right-up
			{ 
				cur -= (n-1);
				lut[i][cur] = 1;
			}
			cur = i;
			while (cur%n > 0 && cur / n > 0) // left-up
			{ 
				cur -= (n+1);
				lut[i][cur] = 1;
			}
		}
	}
};