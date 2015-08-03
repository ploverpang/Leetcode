#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
		if (board.size() != 9)
		{
			return false;
		}
		for (int i = 0; i < board.size(); i++)
		{
			if (board[i].size() != 9)
			{
				return false;
			}
			for (int j = 0; j < board[i].size(); j++)
			{
				if (checkOneElement(board, j, i) == false)
				{
					return false;
				}
			}
		}
		return true;
    }

	void solveSudoku(vector<vector<char>>& board) {
		if (!isValidSudoku(board))
		{
			return;
		}

		vector<pair<int, int>> pointCo;
		for (int i = 0; i < board.size(); i++)
		{
			for (int j= 0; j < board.size(); j++)
			{
				if (board[i][j]=='.')
				{
					pointCo.push_back(make_pair(j, i));
				}	
			}
		}
		
		vector<char> valRecord(pointCo.size());
		solve(board, pointCo, 0, '1', valRecord);
    }

	bool solve(vector<vector<char>>& board, vector<pair<int, int>> &co, int index, char val, vector<char> &valRecord)
	{
		int x = co[index].first;
		int y = co[index].second;

		board[y][x]=val;
		valRecord[index]=val;

		if(isValidSudoku(board))
		{ 
			if(index == co.size()-1)
				return true;
			else
				return(solve(board, co, index+1,'1', valRecord));
		}
		else
		{
			if (val == '9')
			{
				int lastNotNine = index-1;	
				while (lastNotNine >= 0 )
				{
					if (valRecord[lastNotNine] != '9')
					{
						break;
					}
					lastNotNine--;
				}

				if (lastNotNine < 0 )
				{
					return false;
				}
				else
				{
					// look back
					for (int i = lastNotNine+1; i < co.size(); i++)
					{
						//valRecord[i] = '1';
						board[co[i].second][co[i].first] = '.';
					}
					return solve(board, co, lastNotNine, valRecord[lastNotNine]+1, valRecord);
				}
			}
			else
			{
				return solve(board, co, index, val+1, valRecord);
			}
		}
	}

private:
	bool checkOneElement(vector<vector<char>> &board, int x, int y)
	{
		//check row
		vector<int> record(10);
		for (int i = 0; i < board[y].size(); i++)
		{
			if (board[y][i] > '0' && board[y][i] <= '9')
			{
				record[board[y][i]-'0']++;
				if (record[board[y][i]-'0'] == 2)
				{
					return false;
				}
			}
		}
		//check cols
		vector<int> record2(10);
		for (int i = 0; i < board.size(); i++)
		{
			if (board[i][x] > '0' && board[i][x] <= '9')
			{
				record2[board[i][x]-'0']++;
				if (record2[board[i][x]-'0'] == 2)
				{
					return false;
				}
			}
		}
		//check cell
		vector<int> record3(10);
		int cell_start_x = (int)(x/3)*3;
		int cell_start_y = (int)(y/3)*3;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (board[cell_start_y+i][cell_start_x+j] > '0' && board[cell_start_y+i][cell_start_x+j] <= '9')
				{
					record3[board[cell_start_y+i][cell_start_x+j]-'0']++;
					if (record3[board[cell_start_y+i][cell_start_x+j]-'0'] == 2)
					{
						return false;
					}
				}
			}
		}
		return true;
	}
};

void print2DArray(vector<vector<char>> arr)
{
	for (int i = 0; i < arr.size(); i++)
	{
		for (int j = 0; j < arr[i].size(); j++)
		{
			cout << arr[i][j] << '\t';
		}
		cout << endl;
	}
}

int main()
{
	char arr[9][9] = {
	{'5','3','.','.','7','.','.','.','.'},
	{'6','.','.','1','9','5','.','.','.'},
	{'.','9','8','.','.','.','.','6','.'},
	{'8','.','.','.','6','.','.','.','3'},
	{'4','.','.','8','.','3','.','.','1'},
	{'7','.','.','.','2','.','.','.','6'},
	{'.','6','.','.','.','.','2','8','.'},
	{'.','.','.','4','1','9','.','.','5'},
	{'.','.','.','.','8','.','.','7','9'}
	};

	vector<vector<char>> vecArr(9);
	for (int i = 0; i < 9; i++)
	{
		vecArr[i] = vector<char>(arr[i], arr[i]+9);
	}

	Solution sln;
	cout << (sln.isValidSudoku(vecArr) ? "valid" : "unvalid") << endl;
	sln.solveSudoku(vecArr);
	print2DArray(vecArr);
	system("PAUSE");
	return 0;
}